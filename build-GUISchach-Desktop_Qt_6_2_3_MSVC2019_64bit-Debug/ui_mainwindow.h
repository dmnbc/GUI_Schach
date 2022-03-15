/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionneues_Spiel;
    QAction *actionSpiel_laden;
    QAction *actionals_Text;
    QAction *actionals_XML;
    QAction *actionSchachregeln;
    QAction *action_ber_GUI_Schach;
    QWidget *centralwidget;
    QTableWidget *brettAnzeige;
    QPushButton *pushButton;
    QLabel *ladeAnzeige;
    QTextBrowser *dateiInhalt;
    QPushButton *uebernehmen;
    QLabel *spieler1;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *spieler2;
    QRadioButton *usageDatabase;
    QCheckBox *dataBaseConected;
    QMenuBar *menubar;
    QMenu *menuSpiel;
    QMenu *menuSpiel_speichern;
    QMenu *menuHilfe;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        actionneues_Spiel = new QAction(MainWindow);
        actionneues_Spiel->setObjectName(QString::fromUtf8("actionneues_Spiel"));
        actionSpiel_laden = new QAction(MainWindow);
        actionSpiel_laden->setObjectName(QString::fromUtf8("actionSpiel_laden"));
        actionals_Text = new QAction(MainWindow);
        actionals_Text->setObjectName(QString::fromUtf8("actionals_Text"));
        actionals_XML = new QAction(MainWindow);
        actionals_XML->setObjectName(QString::fromUtf8("actionals_XML"));
        actionSchachregeln = new QAction(MainWindow);
        actionSchachregeln->setObjectName(QString::fromUtf8("actionSchachregeln"));
        action_ber_GUI_Schach = new QAction(MainWindow);
        action_ber_GUI_Schach->setObjectName(QString::fromUtf8("action_ber_GUI_Schach"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        brettAnzeige = new QTableWidget(centralwidget);
        if (brettAnzeige->columnCount() < 10)
            brettAnzeige->setColumnCount(10);
        if (brettAnzeige->rowCount() < 10)
            brettAnzeige->setRowCount(10);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        brettAnzeige->setItem(0, 1, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        brettAnzeige->setItem(0, 2, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        brettAnzeige->setItem(0, 3, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        brettAnzeige->setItem(0, 4, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        brettAnzeige->setItem(0, 5, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        brettAnzeige->setItem(0, 6, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        brettAnzeige->setItem(0, 7, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        brettAnzeige->setItem(0, 8, __qtablewidgetitem7);
        brettAnzeige->setObjectName(QString::fromUtf8("brettAnzeige"));
        brettAnzeige->setGeometry(QRect(210, 100, 400, 400));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        brettAnzeige->setFont(font);
        brettAnzeige->viewport()->setProperty("cursor", QVariant(QCursor(Qt::PointingHandCursor)));
        brettAnzeige->setMouseTracking(true);
        brettAnzeige->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        brettAnzeige->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        brettAnzeige->setSelectionBehavior(QAbstractItemView::SelectItems);
        brettAnzeige->setRowCount(10);
        brettAnzeige->setColumnCount(10);
        brettAnzeige->horizontalHeader()->setVisible(false);
        brettAnzeige->horizontalHeader()->setMinimumSectionSize(40);
        brettAnzeige->horizontalHeader()->setDefaultSectionSize(40);
        brettAnzeige->horizontalHeader()->setHighlightSections(false);
        brettAnzeige->verticalHeader()->setVisible(false);
        brettAnzeige->verticalHeader()->setMinimumSectionSize(40);
        brettAnzeige->verticalHeader()->setDefaultSectionSize(40);
        brettAnzeige->verticalHeader()->setHighlightSections(false);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(210, 60, 401, 28));
        ladeAnzeige = new QLabel(centralwidget);
        ladeAnzeige->setObjectName(QString::fromUtf8("ladeAnzeige"));
        ladeAnzeige->setGeometry(QRect(210, 510, 401, 16));
        dateiInhalt = new QTextBrowser(centralwidget);
        dateiInhalt->setObjectName(QString::fromUtf8("dateiInhalt"));
        dateiInhalt->setGeometry(QRect(10, 141, 191, 321));
        QFont font1;
        font1.setPointSize(10);
        dateiInhalt->setFont(font1);
        uebernehmen = new QPushButton(centralwidget);
        uebernehmen->setObjectName(QString::fromUtf8("uebernehmen"));
        uebernehmen->setGeometry(QRect(110, 470, 93, 28));
        spieler1 = new QLabel(centralwidget);
        spieler1->setObjectName(QString::fromUtf8("spieler1"));
        spieler1->setGeometry(QRect(20, 20, 81, 31));
        spieler1->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(110, 20, 113, 22));
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(520, 20, 113, 22));
        spieler2 = new QLabel(centralwidget);
        spieler2->setObjectName(QString::fromUtf8("spieler2"));
        spieler2->setGeometry(QRect(640, 20, 101, 31));
        spieler2->setStyleSheet(QString::fromUtf8("background-color: black;\n"
"color: rgb(255, 255, 255);"));
        usageDatabase = new QRadioButton(centralwidget);
        usageDatabase->setObjectName(QString::fromUtf8("usageDatabase"));
        usageDatabase->setGeometry(QRect(40, 70, 110, 24));
        dataBaseConected = new QCheckBox(centralwidget);
        dataBaseConected->setObjectName(QString::fromUtf8("dataBaseConected"));
        dataBaseConected->setGeometry(QRect(60, 100, 111, 24));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        menuSpiel = new QMenu(menubar);
        menuSpiel->setObjectName(QString::fromUtf8("menuSpiel"));
        menuSpiel_speichern = new QMenu(menuSpiel);
        menuSpiel_speichern->setObjectName(QString::fromUtf8("menuSpiel_speichern"));
        menuHilfe = new QMenu(menubar);
        menuHilfe->setObjectName(QString::fromUtf8("menuHilfe"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuSpiel->menuAction());
        menubar->addAction(menuHilfe->menuAction());
        menuSpiel->addAction(actionneues_Spiel);
        menuSpiel->addAction(menuSpiel_speichern->menuAction());
        menuSpiel->addAction(actionSpiel_laden);
        menuSpiel_speichern->addAction(actionals_Text);
        menuSpiel_speichern->addAction(actionals_XML);
        menuHilfe->addAction(actionSchachregeln);
        menuHilfe->addAction(action_ber_GUI_Schach);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionneues_Spiel->setText(QCoreApplication::translate("MainWindow", "neues Spiel", nullptr));
        actionSpiel_laden->setText(QCoreApplication::translate("MainWindow", "Spiel laden", nullptr));
        actionals_Text->setText(QCoreApplication::translate("MainWindow", "als Text", nullptr));
        actionals_XML->setText(QCoreApplication::translate("MainWindow", "als XML", nullptr));
        actionSchachregeln->setText(QCoreApplication::translate("MainWindow", "Schachregeln", nullptr));
        action_ber_GUI_Schach->setText(QCoreApplication::translate("MainWindow", "\303\234ber GUI Schach", nullptr));

        const bool __sortingEnabled = brettAnzeige->isSortingEnabled();
        brettAnzeige->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem = brettAnzeige->item(0, 1);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "A", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = brettAnzeige->item(0, 2);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "B", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = brettAnzeige->item(0, 3);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = brettAnzeige->item(0, 4);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "D", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = brettAnzeige->item(0, 5);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "E", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = brettAnzeige->item(0, 6);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "F", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = brettAnzeige->item(0, 7);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "G", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = brettAnzeige->item(0, 8);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "H", nullptr));
        brettAnzeige->setSortingEnabled(__sortingEnabled);

        pushButton->setText(QCoreApplication::translate("MainWindow", "Zug xx f\303\274r farbe", nullptr));
        ladeAnzeige->setText(QString());
        uebernehmen->setText(QCoreApplication::translate("MainWindow", "\303\274bernehmen", nullptr));
        spieler1->setText(QCoreApplication::translate("MainWindow", "Spieler-Wei\303\237", nullptr));
        spieler2->setText(QCoreApplication::translate("MainWindow", "Spieler-Schwarz", nullptr));
        usageDatabase->setText(QCoreApplication::translate("MainWindow", "per database", nullptr));
        dataBaseConected->setText(QCoreApplication::translate("MainWindow", "not connected", nullptr));
        menuSpiel->setTitle(QCoreApplication::translate("MainWindow", "Spiel", nullptr));
        menuSpiel_speichern->setTitle(QCoreApplication::translate("MainWindow", "Spiel speichern", nullptr));
        menuHilfe->setTitle(QCoreApplication::translate("MainWindow", "Hilfe", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
