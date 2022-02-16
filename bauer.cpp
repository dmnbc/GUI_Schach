#include "bauer.h"
#include "spiel.h"

Bauer::Bauer()
{
   qDebug()<<"Bauer erstellt";
}

Bauer::Bauer(QString darstellung)
{
    utf8Figur = darstellung;
}

QList<QPair<int,int>> Bauer::erlaubteZieleErrechnen(int row, int column, QString figur)
{
    qDebug()<<__FILE__<<" : "<<__LINE__<<" erlaubteZieleErrechnen Bauer ausgehend von "
            <<row<<","<<column;
        QList<QPair<int,int>> erlaubteFelder;
        // Generelles Vorangehen aus Grundlinie und nach der ersten Bewegung
        int nextRow= row+(this->is_white(figur)?1:-1);
        int nextNextRow = nextRow+(this->is_white(figur)?1:-1);
        // immer, wenn Feld 'vor' dem Bauern leer
        if(Spiel::spielStand.at(nextRow).at(column)._figur->utf8Figur == " ")
        {
            erlaubteFelder.append({nextRow,column});
           // aus der Grundlinie kommend auch übernächstes Feld prüfen
            if( row==2 || row == 7)
            {   if(Spiel::spielStand.at(nextNextRow).at(column)._figur->utf8Figur == " ")
                {
                erlaubteFelder.append({nextNextRow,column});
                }
            }
        }
        // Eventuelles diagonales Schlagen eines Gegners
        // diagonale Felder in Zugrichtung untersuchen
        int col_diagonalLinks  = column+1;
        int col_diagonalRechts = column-1;
        Feld diagonalLinks = Spiel::spielStand.at(nextRow).at(col_diagonalLinks);
        Feld diagonalRechts = Spiel::spielStand.at(nextRow).at(col_diagonalRechts);
             // Feld darf nicht leer sein und nicht mit Figur eigener Farbe
         if( diagonalLinks._figur->utf8Figur != " "
                 && !Figur::is_same_color(diagonalLinks._figur,
                                         Spiel::spielStand.at(row).at(column)._figur))
             {
                erlaubteFelder.append({nextRow,col_diagonalLinks});
             }
         if( diagonalRechts._figur->utf8Figur != " "
                 && !Figur::is_same_color(diagonalRechts._figur,
                                         Spiel::spielStand.at(row).at(column)._figur))
             {
                erlaubteFelder.append({nextRow,col_diagonalRechts});
             }

    qDebug()<<__FILE__<<" : "<<__LINE__<<" Anzahl der erlaubten Ziele" <<erlaubteFelder.size();

        return erlaubteFelder;
}
