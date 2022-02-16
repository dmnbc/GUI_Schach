#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void spielStandZeigen();

private slots:
    void on_brettAnzeige_cellClicked(int row, int column); // Aufnehmen und Absetzen mit Regelprüfung

    void on_brettAnzeige_cellEntered(int row, int column); // Anzeige der möglichen Felder für einen Zug,
                                                           // ausgehend von einem Feld über das die Maus geführt wird

    void on_actionneues_Spiel_triggered();                 // Zurücksetzen auf Grundstellung

    void on_actionSpiel_speichern_triggered();             // einfache Textdatei mit Stand der Figuren erstellen

    void on_actionals_Text_triggered();                    // ruft die Default-Speichermethode auf

    

    void on_actionals_XML_triggered();

void on_actionSpiel_laden_triggered();

    void on_pushButton_uebernehmen();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
