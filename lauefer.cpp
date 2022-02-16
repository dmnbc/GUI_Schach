#include "lauefer.h"
#include "spiel.h"

Lauefer::Lauefer()
{
  qDebug()<<"Lauefer erstellt";
}

Lauefer::Lauefer(QString darstellung)
{
    utf8Figur = darstellung;
}

QList<QPair<int,int>> Lauefer::erlaubteZieleErrechnen(int row, int column, QString figur)
{
    qDebug()<<__FILE__<<" : "<<__LINE__<<" erlaubteZieleErrechnen Läufer ";
        QList<QPair<int,int>> erlaubteFelder;
        int startRow = row;
        int startCol = column;
        // in 4 diagonal Richtungen
        while(Spiel::spielStand.at(++row).at(++column)._figur->utf8Figur == " ")
            erlaubteFelder.append({row,column});
        row=startRow;
        column=startCol;
        while(Spiel::spielStand.at(++row).at(--column)._figur->utf8Figur == " ")
            erlaubteFelder.append({row,column});
        row=startRow;
        column=startCol;
        while(Spiel::spielStand.at(--row).at(--column)._figur->utf8Figur == " ")
            erlaubteFelder.append({row,column});
        row=startRow;
        column=startCol;
        while(Spiel::spielStand.at(--row).at(++column)._figur->utf8Figur == " ")
            erlaubteFelder.append({row,column});

    qDebug()<<__FILE__<<" : "<<__LINE__<<" Anzahl der erlaubten Ziele" <<erlaubteFelder.size();
    return erlaubteFelder;
}
