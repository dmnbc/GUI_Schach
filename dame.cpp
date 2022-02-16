#include "dame.h"
#include "turm.h"
#include "lauefer.h"

Dame::Dame()
{
  qDebug()<<"Dame erstellt";
}

Dame::Dame(QString darstellung)
{
    utf8Figur = darstellung;
}

QList<QPair<int,int>> Dame::erlaubteZieleErrechnen(int row,int column ,QString figur)
{
    qDebug()<<__FILE__<<" : "<<__LINE__<<" erlaubteZieleErrechnen Dame ";
    QList<QPair<int,int>> erlaubteFelder;
    // als Turm bewerten
    Turm* tempT = new Turm("T");
    erlaubteFelder = tempT->erlaubteZieleErrechnen(row,column,"T");
     qDebug()<<__FILE__<<" : "<<__LINE__<<" erlaubteZieleErrechnen als Turm "<<erlaubteFelder;
    Lauefer* tempL = new Lauefer("L");
      qDebug()<<__FILE__<<" : "<<__LINE__<<" erlaubteZieleErrechnen als Läufer "<<tempL->erlaubteZieleErrechnen(row,column,"L");
    erlaubteFelder.append(tempL->erlaubteZieleErrechnen(row,column,"L"));
     qDebug()<<__FILE__<<" : "<<__LINE__<<" erlaubteZieleE insgesamt "<<erlaubteFelder;
    qDebug()<<__FILE__<<" : "<<__LINE__<<" Anzahl der erlaubten Ziele" <<erlaubteFelder.size();
    return erlaubteFelder;
}
