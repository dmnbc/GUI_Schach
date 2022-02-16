#include "koenig.h"

Koenig::Koenig()
{
  qDebug()<<"Koenig erstellt";
}

Koenig::Koenig(QString darstellung)
{
    utf8Figur = darstellung;
}

QList<QPair<int,int>> Koenig::erlaubteZieleErrechnen(int row, int column , QString figur)
{
    qDebug()<<__FILE__<<" : "<<__LINE__<<" erlaubteZieleErrechnen König ";
        QList<QPair<int,int>> erlaubteFelder;
        Dame* tempD = new Dame("D");
        for(auto koord : tempD->erlaubteZieleErrechnen(row,column,"D"))
        {
          if(!(koord.first > row+1 || koord.first < row -1
             || koord.second > column+1 || koord.second < column -1) )
            erlaubteFelder.append({koord.first, koord.second});
        }
        qDebug()<<__FILE__<<" : "<<__LINE__<<" erlaubteZiele für König ab "<<row<<";"<<column<<" sind "<<erlaubteFelder;

    return erlaubteFelder;
}
