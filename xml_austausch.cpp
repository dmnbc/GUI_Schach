#include "xml_austausch.h"

#include <QDebug>
#include "spiel.h"

XML_Austausch::XML_Austausch()
{

}

bool XML_Austausch::zug_aufzeichnen()
{
    qDebug()<<__FILE__<<":"<<__LINE__<<"zug_aufzeichnen()";
    return true;
}

bool XML_Austausch::zug_ergaenzen(QString filename, std::array<std::array<Feld,10>,10> stellung)
{ // https://thecodeprogram.com/how-to-read-and-write-xml-files-in-qt-c--
    qDebug()<<__FILE__<<":"<<__LINE__<<"zug_ergaenzen()";

    QDomDocument gameXML;
        QFile xmlFile(filename);
       // xmlFile.set
        if (!xmlFile.open(QIODevice::ReadOnly | QIODevice::Text ))
        {
            // Error while loading file
            qDebug()<<__FILE__<<":"<<__LINE__<<filename<< " wurde nicht geöffnet";
            return false;
        }
        qDebug()<<__FILE__<<":"<<__LINE__<<xmlFile;
        gameXML.setContent(&xmlFile);
        xmlFile.close();
    qDebug()<<__FILE__<<":"<<__LINE__<<filename<< " ist geöffnet";
    qDebug()<<__FILE__<<":"<<__LINE__<<gameXML.toString();
    QDomElement root = gameXML.documentElement();
    qDebug()<<__FILE__<<":"<<__LINE__<<"root : "<<root.isElement();
    QDomElement zugTag = gameXML.createElement(QString("Zug"));
    zugTag.setAttribute("zugnummer",QString::number(Spiel::zugnummer));
    QDomElement stellungTag = gameXML.createElement(QString("Stellung"));
    QString stellungString;
    for(int i = 1; i <= 8; i++)
       for(int j = 1; j <= 8; j++)
        {
           stellungString += Spiel::spielStand.at(i).at(j)._figur->utf8Figur.toUtf8();
           qDebug()<<__FILE__<<":"<<__LINE__<<stellungString;
       }

    QDomText stellungText = gameXML.createTextNode(stellungString);
    stellungTag.appendChild(stellungText);

    zugTag.appendChild(stellungTag);


    root.appendChild(zugTag);
    if(!xmlFile.open(QIODevice::WriteOnly  | QIODevice::Text))
    {
         qDebug()<<__FILE__<<":"<<__LINE__<<filename<< " wurde nicht geöffnet";
         return false;
    }

    QTextStream output(&xmlFile);
    output << gameXML.toString();
    xmlFile.close();

    return true;
}
