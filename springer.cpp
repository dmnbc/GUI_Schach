#include "springer.h"

Springer::Springer()
{
  qDebug()<<"Springer erstellt";
}

Springer::Springer(QString darstellung)
{
    utf8Figur = darstellung;
}

QList<QPair<int,int>> Springer::erlaubteZieleErrechnen(int row,int column,QString figur)
{
    qDebug()<<__FILE__<<" : "<<__LINE__<<" erlaubteZieleErrechnen Springer ";
        QList<QPair<int,int>> erlaubteFelder;
        QList<QPair<int,int>> spruenge = {{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{2,-1},{-1,-2},{1,-2}};
        // todo: fehlt noch die Beachtung der Randlagen -> Absturz
        for(auto aenderung : spruenge)
        {
            if(       row+aenderung.first>0 && row+aenderung.first < 9
              && column+aenderung.second >0 && column+aenderung.second < 9)
            erlaubteFelder.append({row+aenderung.first,column+aenderung.second});
        }



    qDebug()<<__FILE__<<" : "<<__LINE__<<" Anzahl der erlaubten Ziele" <<erlaubteFelder.size();
    return erlaubteFelder;
}
