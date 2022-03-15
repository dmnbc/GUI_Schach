/* Projekt GUISchach Februrar 2022 in Fachmodul II
 * ctor:
 * Aufbau der Oberfläche
 * erstellt die Grundstellung der Figuren in einem statischen 2 dim Array spiel.spielStand
 * QTableWidget mit Grundstellung füllen und anzeigen
 *
 * event-Management
 * cellClicked(int row, int column)
 *     {Aufnehmen einer Figur bei geraden clicknummern 0,2,4
 *      Absetzen der aufgenommenen Figur bei ungerader clicknummer 1,3,5,
 *      - Prüfen der Felder über eine Liste erlaubter Felder
 *          Die Berechnung der erlaubten Felder erfolgt in den Klassen der einzelnen Figurtypen
 *      spielStandZeigen()}
 *
 * cellEntered(int row, int column)
 *     { Beim MouseOver der Spielfelder erfolgt eine Anzeige der jeweils erlaubten Felder }
 *
 * spielStandZeigen()
 *     { Aktualisieren der Oberfläche, Positionen der Figuren,
 *       Anzeige der Zugnummer, Umschalten der Spieleranzeige}
 *
 *  menue-Steuerung
 *  neues_Spiel_triggered()
 *     { Teilweise Kopie des ctor, neue Grundstellung der Figuren und Anzeige}
 *
 *  Spiel_speichern_triggered()
 *     { Aufruf FileDialog und einfaches Schreiben des Spielstandes ( UTF-8 Textdatei )}
 *     Submenue
 *        als Text default Methode, wird von on_actionals_Text_triggered aufgerufen
 *        als XML on_actionals_XML_triggered mit  QXmlStreamWriter
 *
 *   Spiel laden on_actionSpiel_laden_triggered()
 *        grundsätzlich wird ein Dateiname der zu ladenden Datei erfragt
 *        je nach gewählter Endung ( .txt / .xml ) erfolgt das Einlesen in ein Vorschaufenster
 *        von dort kann der Spielstand übernommen werden
 */


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "spiel.h"
#include "xml_austausch.h"
#include "database.h"

#include <Qt>
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>
#include <fstream>
#include <QTime>
#include <QtXml>
#include <QTextStream>
#include <QScrollBar>

QSqlDatabase Database::db;
bool Database::connected = false;
std::array<std::array<Feld,10>,10> Spiel::spielStand;
QString Spiel::aufgenommeneFigur;
Figur* Spiel::aufgenommene_Figur;
int Spiel::clicknummer = 0;
QPair<int,int> Spiel::last_even_clickPosition = {0,0};
bool Spiel::spieler = true;
int Spiel::zugnummer = 1;
QString Spiel::xmlFile;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QColor hell;
    hell.setRgb(255,255,220);
    QColor dunkel;
    dunkel.setRgb(128,220,128);
    QColor neutral;
    neutral.setRgb(100,100,100);

    ui->pushButton->setStyleSheet("background-color: white; color: black");
    ui->pushButton->setText("Neues Spiel - Weiss am Zug");

    ui->dateiInhalt->verticalScrollBar()->setPageStep(9);
    //ui->dateiInhalt->verticalScrollBar()->

   qDebug()<<__FILE__<<":"<<__LINE__<<" Instanzieren von Spiel spiel";
   Spiel spiel; // schafft die Grundstellung auf dem Brett
                 // in einem 2 dim Array spiel.spielStand
   qDebug()<<__FILE__<<":"<<__LINE__<<" Nach Instanzieren von Spiel spiel";
    // QTableWidget mit Grundstellung füllen und anzeigen
    for(int row = 0; row <10;row++)
    {
        for(int column=0; column <10;column++)
        { // qDebug()<<__FILE__<<":"<<__LINE__<<": "<<row<<","<<column;
        QTableWidgetItem* feld = new QTableWidgetItem;
        feld->setTextAlignment(Qt::AlignCenter); // qDebug()<<__FILE__<<":"<<__LINE__;
        feld->setText(spiel.spielStand.at(row).at(column)._figur->utf8Figur);//qDebug()<<__FILE__<<":"<<__LINE__;
        feld->setBackground((row*column!=0 && row != 9 && column !=9 )?(row+column)%2?hell:dunkel:neutral);
        ui->brettAnzeige->setItem(row,column,feld); // qDebug()<<__FILE__<<":"<<__LINE__;
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_brettAnzeige_cellClicked(int row, int column)
{ Figur* aktuelleFigur =  Spiel::spielStand.at(row).at(column)._figur;
   if(Spiel::clicknummer%2==0) // Aufnehmen einer Figur bei geraden clicknummern 0,2,4,......
   {
       if(Spiel::spielStand.at(row).at(column).erlaubteZiele.size())
       {
       qDebug()<<__FILE__<<" : "<<__LINE__<<" Feld "<<row<<";"<<column<<" on_brettAnzeige_cellClicked, Figur wird aufgenommen "
           <<aktuelleFigur->utf8Figur.toUtf8();
       Spiel::aufgenommene_Figur=aktuelleFigur; qDebug()<<__FILE__<<" : "<<__LINE__<<" Feld "<<row<<";"<<column<<" aufgenommen ist "
           <<Spiel::aufgenommene_Figur->utf8Figur.toUtf8();
       Spiel::spielStand.at(row).at(column)._figur=new NoFigur(" "); qDebug()<<__FILE__<<" : "<<__LINE__<<" Feld "<<row<<";"<<column<<" wird ersetzt mit "
           <<Spiel::spielStand.at(row).at(column)._figur->utf8Figur.toUtf8();
       for(auto rowColumn: Spiel::spielStand.at(row).at(column).erlaubteZiele)
       {
           ui->brettAnzeige->item(rowColumn.first, rowColumn.second)->setSelected(true);
       }
       Spiel::last_even_clickPosition={row,column};
        Spiel::clicknummer++;
         spielStandZeigen();
       }
       else
       {
           QMessageBox msgBox;
            msgBox.setText("von Hier kann nicht gezogen werden, Figur blockiert");
            msgBox.exec();
       }
   }
   else // Absetzen der aufgenommenen Figur bei ungerader clicknummer 1,3,5, ....
    {  bool erlaubt = false;
       qDebug()<<__FILE__<<" : "<<__LINE__<<" Feld "<<row<<";"<<column<<" prüfen, ob  ist in der Liste von Feld"
               <<Spiel::last_even_clickPosition<<" "<<Spiel::spielStand.at(Spiel::last_even_clickPosition.first).at(Spiel::last_even_clickPosition.second).erlaubteZiele;
       // dursuchen der erlaubten Ziel nach {row,column}
       for(auto pair : Spiel::spielStand.at(Spiel::last_even_clickPosition.first).at(Spiel::last_even_clickPosition.second).erlaubteZiele)
       {   qDebug()<<__FILE__<<" : "<<__LINE__<<row<<";"<<column<<" vergleichen mit "<<pair;
           if(pair.first == row && pair.second == column)
            {
                 erlaubt = true;
                 break;
           }
       }
       qDebug()<<__FILE__<<" : "<<__LINE__<<"erlaubtes Feld gefunden :"<<erlaubt;
       if(!erlaubt)
        {  qDebug()<<__FILE__<<" : "<<__LINE__<<"kein erlaubtes Feld gefunden : Zeige Warnung";
           QMessageBox msgBox;
            msgBox.setText("Unerlaubtes Feld");
            msgBox.exec();
        }
       else
        { qDebug()<<__FILE__<<" : "<<__LINE__<<"erlaubtes Feld gefunden : Figur setzen ";
       Spiel::spielStand.at(row).at(column)._figur=Spiel::aufgenommene_Figur;
       qDebug()<<__FILE__<<" : "<<__LINE__<<" Feld "<<row<<";"<<column<<" on_brettAnzeige_cellClicked, Figur wird abgesetzt "
                  <<Spiel::spielStand.at(row).at(column)._figur->utf8Figur.toUtf8();
       //Neue Berechnung der erlaubten Felder für das innere Brett
       for (int row = 1;row <= 8 ;row++ ) {
           for (int column = 1;column <= 8 ;column++ ) {
               qDebug()<<__FILE__<<" : "<<__LINE__<<" Feld "<<row<<";"<<column<<" besetzt mit "
                        <<Spiel::spielStand.at(row).at(column)._figur->utf8Figur.toUtf8();
               // polymorphes Aufrufen, je nach figurTyp
               Spiel::spielStand.at(row).at(column).erlaubteZiele =
               Spiel::spielStand.at(row).at(column)._figur->erlaubteZieleErrechnen(row, column, Spiel::spielStand.at(row).at(column)._figur->utf8Figur);
           }
       }
       Spiel::clicknummer++;
       Spiel::zugnummer++;
       Spiel::spieler = !Spiel::spieler;
       XML_Austausch xml_objekt;
       xml_objekt.zug_ergaenzen(Spiel::xmlFile,Spiel::spielStand);
       spielStandZeigen();

        }
    }


}


void MainWindow::on_brettAnzeige_cellEntered(int row, int column)
{ // qDebug()<<__FILE__<<" : "<<__LINE__<<" Feld "<<row<<";"<<column<<" kann sich bewegen nach "<< Spiel::spielStand.at(row).at(column).erlaubteZiele;
    if(Spiel::clicknummer%2==0)
    {
        ui->brettAnzeige->clearSelection();
        for(auto rowColumn: Spiel::spielStand.at(row).at(column).erlaubteZiele)
        {
            ui->brettAnzeige->item(rowColumn.first, rowColumn.second)->setSelected(true);
        }
    }
}


void MainWindow::spielStandZeigen()
{
    qDebug()<<__FILE__<<";"<<__LINE__<<"spielStandZeigen()";
    QColor hell;
    hell.setRgb(255,255,220);
    QColor dunkel;
    dunkel.setRgb(128,220,128);
    QColor neutral;
    neutral.setRgb(100,100,100);
    for(int row = 0; row <10;row++)
    {
        for(int column=0; column <10;column++)
        {
        QTableWidgetItem* feld = new QTableWidgetItem;
        feld->setTextAlignment(Qt::AlignCenter);
        feld->setText(Spiel::spielStand.at(row).at(column)._figur->utf8Figur);
        qDebug()<<__FILE__<<";"<<__LINE__<<row<<":"<<column<<" -> "<<Spiel::spielStand.at(row).at(column)._figur->utf8Figur;
        feld->setBackground((row*column!=0 && row != 9 && column !=9 )?(row+column)%2?hell:dunkel:neutral);
        ui->brettAnzeige->setItem(row,column,feld);
        // Umschalten der Spieleranzeige
        if(Spiel::spieler)
         { ui->pushButton->setStyleSheet("background-color: white; color: black");
           ui->pushButton->setText("Zug: "+QString::number(Spiel::zugnummer)+ " Weiss am Zug");}
        else
            {
            ui->pushButton->setStyleSheet("background-color: black; color: white");
            ui->pushButton->setText("Zug: "+QString::number(Spiel::zugnummer)+" Schwarz am Zug");
            }
        }
    }
}


void MainWindow::on_actionneues_Spiel_triggered()
{   QColor hell;
    hell.setRgb(255,255,220);
    QColor dunkel;
    dunkel.setRgb(128,220,128);
    QColor neutral;
    neutral.setRgb(100,100,100);
    QMessageBox msgBox;
     msgBox.setText("Ein neues Spiel setzt alle Figuren wieder in die Grundstellung\nWollen Sie wirklich ein neues Spiel?");
     msgBox.setStandardButtons(QMessageBox::Yes);
     msgBox.addButton(QMessageBox::No);
     msgBox.setDefaultButton(QMessageBox::No);
     if(msgBox.exec() == QMessageBox::Yes){ // neues Spiel
         Spiel spiel; // schafft die Grundstellung auf dem Brett
                       // in einem 2 dim Array spiel.spielStand
         qDebug()<<__FILE__<<":"<<__LINE__<<" Nach Instanzieren von Spiel spiel";
          // QTableWidget mit Grundstellung füllen und anzeigen
         Spiel::clicknummer=0;
         Spiel::spieler=true; // true ist der weisse Spieler
         ui->pushButton->setStyleSheet("background-color: white; color: black");
         ui->pushButton->setText("Neues Spiel - Weiss am Zug");
          for(int row = 0; row <10;row++)
          {
              for(int column=0; column <10;column++)
              { // qDebug()<<__FILE__<<":"<<__LINE__<<": "<<row<<","<<column;
              QTableWidgetItem* feld = new QTableWidgetItem;
              feld->setTextAlignment(Qt::AlignCenter); // qDebug()<<__FILE__<<":"<<__LINE__;
              feld->setText(spiel.spielStand.at(row).at(column)._figur->utf8Figur);//qDebug()<<__FILE__<<":"<<__LINE__;
              feld->setBackground((row*column!=0 && row != 9 && column !=9 )?(row+column)%2?hell:dunkel:neutral);
              ui->brettAnzeige->setItem(row,column,feld); // qDebug()<<__FILE__<<":"<<__LINE__;
              Spiel::zugnummer=1;
              }
          }
     }else {
       // Spiel fortsetzen
     }
}


void MainWindow::on_actionSpiel_speichern_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(nullptr,"Sicherungsdatei auswählen");
    qDebug()<<__FILE__<<":"<<__LINE__<<": "<<fileName<<" ausgewählt";

    QMessageBox msgBox;
     msgBox.setText("Soll an \n"+fileName.split("/").last()+"\nangehangen werden (Yes) oder soll überschrieben werden (No)?");
     msgBox.setStandardButtons(QMessageBox::Yes);
     msgBox.addButton(QMessageBox::No);
     std::ios_base::openmode mode;
     if(msgBox.exec() == QMessageBox::Yes)
     {
        mode   = std::ios::app;
     }
     else
     {
        mode = std::ios::trunc;
     }
     std::ofstream sicherung(fileName.toStdString(), mode);
     sicherung<<("\nSpiel am "+QDate::currentDate().toString()+" um "+QTime::currentTime().toString()+
                " zwischen "+ui->lineEdit->text()+" und "+ui->lineEdit_2->text() +
                 " vor Zug "+QString::number(Spiel::zugnummer)+"\n").toStdString();
    for(int row = 1; row <= 8; row++)
    {
        for(int col = 1; col <= 8; col++)
        {   QString data = Spiel::spielStand.at(row).at(col)._figur->utf8Figur;
            //sicherung<<" . ";
            sicherung<<data.toStdString().c_str();
        }
        sicherung<<"\n";
    }
    sicherung.close();
}

void MainWindow::on_actionals_Text_triggered()
{
    on_actionSpiel_speichern_triggered();
}

void MainWindow::on_actionals_XML_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(nullptr,"Datei zum Speichern  auswählen",
                                                    " ","Dateien (*.xml *.txt)");
    Spiel::xmlFile = fileName;
    QFile wrtFile(fileName);
    if (!wrtFile.open(QIODevice::WriteOnly))
    {
        qDebug() << "wrt.xml Already opened or there is another issue";
        wrtFile.close();
    }
    QXmlStreamWriter *xmlWriter = new QXmlStreamWriter(&wrtFile);
    xmlWriter->writeStartDocument();
    xmlWriter->setAutoFormatting(true);
    xmlWriter->writeStartElement("Schachpartie");
     xmlWriter->writeStartElement("daten");
      xmlWriter->writeStartElement("Spieler");
        xmlWriter->writeAttribute("weiss", ui->lineEdit->text());
        xmlWriter->writeAttribute("schwarz", ui->lineEdit_2->text());
      xmlWriter->writeEndElement(); // Spieler
      xmlWriter->writeStartElement("Datum");
       xmlWriter->writeAttribute("am ",QDate::currentDate().toString());
       xmlWriter->writeAttribute("um ",QTime::currentTime().toString());
      xmlWriter->writeEndElement(); //Datum
     xmlWriter->writeEndElement(); //daten
    QString figurenStellung = ""; // alle 64 Felder sammeln
    for(int row = 1; row <= 8; row++)
    {
        for(int col = 1; col <= 8; col++)
        {   QString data = Spiel::spielStand.at(row).at(col)._figur->utf8Figur;
            figurenStellung +=data; //jedes Feld an den String anhängen
        }
    }
     qDebug()<<__FILE__<<":"<<__LINE__<<"data = "<<figurenStellung.toUtf8();
     int i = Spiel::zugnummer;
        xmlWriter->writeStartElement("Zug");
         xmlWriter->writeAttribute("zugnummer",QString::number(i) );
         xmlWriter->writeTextElement("stellung",figurenStellung);
        xmlWriter->writeEndElement(); // Zug

    xmlWriter->writeEndElement(); // Schachpartie
    xmlWriter->writeEndDocument();
}


void MainWindow::on_actionSpiel_laden_triggered()
{
    // Datei zum Laden auswählen
    QString fileName = QFileDialog::getOpenFileName(nullptr,"Spieldatei zum Laden auswählen",
                                                    " ","Spiele (*.txt *.xml *.json)");
    qDebug()<<__FILE__<<":"<<__LINE__<<": "<<fileName<<" ausgewählt";


    int fileType = 0;
    // nachfragen, ob txt oder xml Datei
    if(fileName.right(3) == "txt")
    {fileType = 1;  qDebug()<<__FILE__<<":"<<__LINE__<<" .txt erkannt";}
    else
    {
        fileType = 2;qDebug()<<__FILE__<<":"<<__LINE__<<" .xml erkannt";
    }
    QFile datei(fileName);
    QTextStream sicherung(&datei); qDebug()<<__FILE__<<":"<<__LINE__<<": QTextstream erzeugt";
    QXmlStreamReader reader(&datei);
    if(datei.open(QIODevice::ReadOnly))
    {
        QString line;
        if(fileType==1) // txt
         {while(!sicherung.atEnd())
            { // lesen
              qDebug()<<__FILE__<<":"<<__LINE__<<": sicherung.atEnd = "+ QVariant(sicherung.atEnd()).toString();
              line = sicherung.readLine(); qDebug()<<__FILE__<<":"<<__LINE__<<": zeilenweise lesen";
              qDebug()<<__FILE__<<":"<<__LINE__ << line.toUtf8()<<" mit "<<line.size()<<" Zeichen"; // convert to locale multi-byte string
              ui->ladeAnzeige->setText(line);
              ui->dateiInhalt->setText(sicherung.readAll());
            }
            qDebug()<<__FILE__<<":"<<__LINE__<<": sicherung.atEnd = "+ QVariant(sicherung.atEnd()).toString();
        }
        else // xml
        {
            QString newLine;
            while (!reader.atEnd()) {
                    qDebug()<<__FILE__<<":"<<__LINE__ <<"do processing";

                    reader.readNextStartElement();  qDebug()<<__FILE__<<":"<<__LINE__<<reader.name().toString() <<" gefunden ";
                    if(reader.name().toString() == "Spieler")
                    {
                        qDebug()<<__FILE__<<":"<<__LINE__<<reader.attributes().value("weiss").toString();
                        qDebug()<<__FILE__<<":"<<__LINE__<<reader.attributes().value("schwarz").toString();
                        newLine += reader.attributes().value("weiss").toString();

                    }
                    if(reader.name().toString() == "stellung")
                    { qDebug()<<__FILE__<<":"<<__LINE__ <<"stellung gefunden";
                      QString line = reader.readElementText();
                      qDebug()<<__FILE__<<":"<<__LINE__ <<line<<" mit "<<line.size()<<" Zeichen";
                      ui->ladeAnzeige->setText(line);
                      newLine += "*------*\n";
                      for(int i = 1; i <=line.size();i++)
                      {
                          newLine += line.at(i-1);
                          if( i%8 == 0)
                            {  newLine += "-\n";}

                      }
                      qDebug().noquote()<<__FILE__<<":"<<__LINE__<<"\n"<<newLine.toUtf8();
                      qDebug().noquote()<<__FILE__<<":"<<__LINE__ <<newLine<<" mit "<<newLine.size()<<" Zeichen";
                      ui->dateiInhalt->setText(newLine);}
              }
        }
    }
}



void MainWindow::on_dateiInhalt_selectionChanged()
{   static int events;
    //qDebug()<<__FILE__<<":"<<__LINE__<<"selectionChanged : "<<events++ << "Selected : "<<ui->dateiInhalt->textCursor().selectedText();
    //ui->ladeAnzeige->text()=ui->dateiInhalt->textCursor().selectedText();
}


void MainWindow::on_dateiInhalt_cursorPositionChanged()
{  static int events;
    //qDebug()<<__FILE__<<":"<<__LINE__<<"PositionChanged : "<<events++ <<__FILE__<<":"<<__LINE__<<"Selected : "<<ui->dateiInhalt->textCursor().selectedText();
    //ui->ladeAnzeige->text()=ui->dateiInhalt->textCursor().selectedText();

}


void MainWindow::on_uebernehmen_clicked()
{   qDebug()<<__FILE__<<":"<<__LINE__<<": uebernehmen()";
        QTextCursor Cursor(ui->dateiInhalt->textCursor());
        qDebug()<<__FILE__<<":"<<__LINE__<<": gewählter Text  :"<<Cursor.selectedText().toUtf8();
        // Übernahme des geladenen Spielstandes ( Inhalt des Textbrowsers )
        QString text = Cursor.selectedText(); // ui->dateiInhalt->toPlainText();
        qDebug()<<__FILE__<<":"<<__LINE__<<": dateiInhalt als String :"<<text.toUtf8();
        qDebug()<<__FILE__<<":"<<__LINE__<<": der String hat "<<text.size();
        // Hole die 64 Darstellungen der Figuren
        // 64 Zeichen am Ende des Strings, Annahme dass jedes Zeichen 1 character braucht
        qDebug()<<__FILE__<<":"<<__LINE__<<": der String hat als letztes Zeichen "<<text.at(text.size()-1);
        int zeile = 8; // da Datei mit \n endet
        int spalte = 8; //9;
        int i;
        for(i = text.size()-1; i > 0 ; i--)
           { qDebug()<<__FILE__<<":"<<__LINE__<<"auf Position "<<i<<" : "<<text.at(i);
               switch(text.at(i).unicode())
               // Erkennen, welche Subklasse von Figur dargestellt wird
               {
               case 9812: qDebug()<<__FILE__<<":"<<__LINE__<<"White king";
                  Spiel::spielStand.at(zeile).at(spalte--)._figur = new Koenig(text.at(i));
                  break;
               case 9813: qDebug()<<__FILE__<<":"<<__LINE__<<"White queen";
                   Spiel::spielStand.at(zeile).at(spalte--)._figur = new Dame(text.at(i));
                  break;
               case 9814: qDebug()<<__FILE__<<":"<<__LINE__<<"White rook";
                   Spiel::spielStand.at(zeile).at(spalte--)._figur = new Turm(text.at(i));
                  break;
               case 9815: qDebug()<<__FILE__<<":"<<__LINE__<<"White bishop";
                   Spiel::spielStand.at(zeile).at(spalte--)._figur = new Lauefer(text.at(i));
                  break;
               case 9816: qDebug()<<__FILE__<<":"<<__LINE__<<"White knight";
                   Spiel::spielStand.at(zeile).at(spalte--)._figur = new Springer(text.at(i));
                 break;
               case 9817: qDebug()<<__FILE__<<":"<<__LINE__<<"White pawn";
                   Spiel::spielStand.at(zeile).at(spalte--)._figur = new Bauer(text.at(i));
                  break;
               case 9818: qDebug()<<__FILE__<<":"<<__LINE__<<"Black king";
                   Spiel::spielStand.at(zeile).at(spalte--)._figur = new Koenig(text.at(i));
                  break;
               case 9819: qDebug()<<__FILE__<<":"<<__LINE__<<"Black queen";
                   Spiel::spielStand.at(zeile).at(spalte--)._figur = new Dame(text.at(i));
                  break;
               case 9820: qDebug()<<__FILE__<<":"<<__LINE__<<"Black rook";
                  Spiel::spielStand.at(zeile).at(spalte--)._figur = new Turm(text.at(i));
                  break;
               case 9821: qDebug()<<__FILE__<<":"<<__LINE__<<"Black bishop";
                  Spiel::spielStand.at(zeile).at(spalte--)._figur = new Lauefer(text.at(i));
                  break;
               case 9822: qDebug()<<__FILE__<<":"<<__LINE__<<"Black knight";
                  Spiel::spielStand.at(zeile).at(spalte--)._figur = new Springer(text.at(i));
                  break;
               case 9823: qDebug()<<__FILE__<<":"<<__LINE__<<"Black pawn";
                   Spiel::spielStand.at(zeile).at(spalte--)._figur = new Bauer(text.at(i));                  
                   break;
               case 32:
                   qDebug()<<__FILE__<<":"<<__LINE__<<"leeres Feld";
                   Spiel::spielStand.at(zeile).at(spalte--)._figur = new NoFigur(text.at(i));
                  break;
               case 8233:
                  qDebug()<<__FILE__<<":"<<__LINE__<<"8233";
                  zeile--;
                  spalte = 8;
               default: qDebug()<<__FILE__<<":"<<__LINE__<<"Noch unbestimmt";
                   break;
               }
               if(spalte == -1) //
                  spalte = 8;   //
               qDebug()<<__FILE__<<":"<<__LINE__<<zeile<<";"<<spalte;

           }
           spielStandZeigen();
           qDebug()<<__FILE__<<":"<<__LINE__<<"Vor dem Spielfeld steht";
           QString zugNr = text.left(i).right(2);
           Spiel::zugnummer=zugNr.toInt();
           if(Spiel::zugnummer%2)
            { ui->pushButton->setStyleSheet("background-color: white; color: black");
              ui->pushButton->setText("Zug: "+QString::number(Spiel::zugnummer)+ " Weiss am Zug");}
           else
               {
               ui->pushButton->setStyleSheet("background-color: black; color: white");
               ui->pushButton->setText("Zug: "+QString::number(Spiel::zugnummer)+" Schwarz am Zug");
               }

    }


void MainWindow::on_usageDatabase_toggled(bool checked)
{
     qDebug()<<__FILE__<<":"<<__LINE__<<"Datenbank soll "<<(checked?"":"nicht ")<<"genutzt werden";
     // Versuch die Datenbank anzusprechen
         qDebug()<<__FILE__<<":"<<__LINE__<<"Try to connect";

         // Datenbank objekt erstellen und verbinden
         Database db("QMYSQL");qDebug()<<__FILE__<<":"<<__LINE__<<"db Instanz ";


         if(!Database::connected)
         // nicht verbunde -> Fehlermeldung
         {   qDebug()<<__FILE__<<":"<<__LINE__<<"Database::connected is "<<Database::connected;

             ui->dataBaseConected->setStyleSheet("color:red");
             ui->dataBaseConected->setText("not connected");
             ui->dataBaseConected->setChecked(false);
         }
         else
         // Verbindungsanzeige aktuallisieren
         {   qDebug()<<__FILE__<<":"<<__LINE__<<"Database::connected is "<<Database::connected;
             ui->dataBaseConected->setStyleSheet("color:green");
             ui->dataBaseConected->setText("connected");
             ui->dataBaseConected->setChecked(true);

             Database::results("use chess");
             QString spielstand = Database::results("select * from zug order by zug_id DESC limit 1").at(1).at(3);
             ui->dateiInhalt->setText(spielstand);
             qDebug()<<__FILE__<<":"<<__LINE__<<spielstand<<" hat "<<spielstand.size()<<" Zeichen";
         }
}

