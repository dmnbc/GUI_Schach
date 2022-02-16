#include "nofigur.h"

NoFigur::NoFigur()
{

}

NoFigur::NoFigur(QString inhalt)
{
  utf8Figur = inhalt;
}

QList<QPair<int,int>> NoFigur::erlaubteZieleErrechnen()
{
    qDebug()<<__FILE__<<" : "<<__LINE__<<" erlaubteZieleErrechnen Leeres Feld ";
        QList<QPair<int,int>> erlaubteFelder;
        erlaubteFelder.append({0,0});
    qDebug()<<__FILE__<<" : "<<__LINE__<<" Anzahl der erlaubten Ziele" <<erlaubteFelder.size();
    return erlaubteFelder;
}
