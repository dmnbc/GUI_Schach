#include "figur.h"

Figur::Figur()
{

}

QList<QPair<int,int>> Figur::erlaubteZieleErrechnen(int row, int column,QString figur)
{
   // qDebug()<<__FILE__<<" : "<<__LINE__<<" erlaubteZieleErrechnen für "
   //         <<figur.toUtf8();
    QList<QPair<int,int>> erlaubteFelder;
    // qDebug()<<__FILE__<<" : "<<__LINE__<<" Anzahl der erlaubten Ziele" <<erlaubteFelder.size();
        return erlaubteFelder;
}

bool Figur::is_white(QString s)
{
    return s < "♚";
}

bool Figur::is_same_color(Figur* f1, Figur* f2)
{
    return is_white(f1->utf8Figur) ==is_white(f2->utf8Figur);
}
