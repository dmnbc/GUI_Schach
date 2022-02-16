#include "turm.h"
#include "spiel.h"

Turm::Turm()
{
 qDebug()<<"Turm erstellt";
}

Turm::Turm(QString darstellung)
{
    utf8Figur = darstellung;
}

QList<QPair<int,int>> Turm::erlaubteZieleErrechnen(int row,int column,QString figur)
{
    qDebug()<<__FILE__<<" : "<<__LINE__<<" erlaubteZieleErrechnen Turm ";
        QList<QPair<int,int>> erlaubteFelder;
        int startRow = row;
        int startCol = column;
        // senkrecht nach oben und unten ( bis Rand, oder Figur ( fremde schlagen ))
        while(Spiel::spielStand.at(++row).at(column)._figur->utf8Figur == " ")
        {
                erlaubteFelder.append({row,column});
        }
        row = startRow;
        while(Spiel::spielStand.at(--row).at(column)._figur->utf8Figur == " ")
        {
                erlaubteFelder.append({row,column});
        }

         // horizontal nach rechts und links ( bis Rand, oder Figur ( fremde schlagen ))
        while(Spiel::spielStand.at(startRow).at(++column)._figur->utf8Figur == " ")
        {
                erlaubteFelder.append({startRow,column});
        }
        column = startCol;
        while(Spiel::spielStand.at(startRow).at(--column)._figur->utf8Figur == " ")
        {
                erlaubteFelder.append({startRow,column});
        }

    qDebug()<<__FILE__<<" : "<<__LINE__<<" Anzahl der erlaubten Ziele" <<erlaubteFelder.size();
    return erlaubteFelder;
}
