#include "feld.h"
#include <QtDebug>

Feld::Feld()
{

}

Feld::Feld(int row,int column)
{
        QString whiteKing   {"♔"}; // "\xE2\x99\x94"
        QString whiteQueen 	{"♕"}; // "\xE2\x99\x95"
        QString whiteRook 	{"♖"}; // "\xE2\x99\x96"
        QString whiteBishop	{"♗"}; // "\xE2\x99\x97"
        QString whiteKnight	{"♘"}; // "\xE2\x99\x98"
        QString whitePawn 	{"♙"}; // "\xE2\x99\x99"
        QString blackKing 	{"♚"}; // "\xE2\x99\x9A"
        QString blackQueen 	{"♛"}; // "\xE2\x99\x9B"
        QString blackRook 	{"♜"}; // "\xE2\x99\x9C"
        QString blackBishop {"♝"}; // "\xE2\x99\x9D"
        QString blackKnight {"♞"}; // "\xE2\x99\x9E"
        QString blackPawn 	{"♟"}; // "\xE2\x99\x9F"

qDebug()<<__FILE__<<":"<<__LINE__<<blackPawn.toUtf8();
    switch(column)
        {
          case 0:
          case 9:if(row>0 && row < 9)
           { _figur = new NoFigur(QString(QChar::fromLatin1(char(48+row))));}
            else
             _figur =new NoFigur(" " );
            break;
          default:
           //  _figur = (row==2?new Bauer(whitePawn):row==7?new Bauer(blackPawn):new Bauer(" "));

             if(row==2)
                 _figur = new Bauer(whitePawn);
             if(row==7)
                 _figur = new Bauer(blackPawn);
             if(row!=2 && row != 7)
                 _figur = new NoFigur(" ");

            switch(row)
            {
            case 0:
            case 9:_figur =new NoFigur(QString(QChar::fromLatin1(char(64+column))));
                break;
            case 1:
                if(column==1 || column==8 )
                   _figur = new Turm(whiteRook);
                if(column==2 || column==7 )
                    _figur = new Springer(whiteKnight);
                if(column==3 || column==6 )
                    _figur = new Lauefer(whiteBishop);
                if( column==4 )
                    _figur = new Koenig(whiteKing);
                if (column==5 )
                    _figur = new Dame(whiteQueen);
                break;
            case 8:
                if(column==1 || column==8 )
                   _figur = new Turm(blackRook);
                if(column==2 || column==7 )
                    _figur = new Springer(blackKnight);
                if(column==3 || column==6 )
                    _figur = new Lauefer(blackBishop);
                if( column==4 )
                    _figur = new Koenig(blackKing);
                if (column==5 )
                    _figur = new Dame(blackQueen);
                break;
            }
            //qDebug()<<__FILE__<<":"<<__LINE__;
    }
    //qDebug()<<__FILE__<<":"<<__LINE__;
    // Bauern aus der Grundstellung
    if(row == 2 && (column > 0 && column < 9 ))
    { //qDebug()<<__FILE__<<":"<<__LINE__;
        erlaubteZiele.append({row+1,column});//qDebug()<<__FILE__<<":"<<__LINE__;
        erlaubteZiele.append({row+2,column});//qDebug()<<__FILE__<<":"<<__LINE__;
    }
    //qDebug()<<__FILE__<<":"<<__LINE__;
    if(row == 7 && (column > 0 && column < 9 ))
    {
        erlaubteZiele.append({row-1,column});//qDebug()<<__FILE__<<":"<<__LINE__;
        erlaubteZiele.append({row-2,column});//qDebug()<<__FILE__<<":"<<__LINE__;
    }
    // Pferde aus der Grundstellung
    //qDebug()<<__FILE__<<":"<<__LINE__;
    if(row==1 && (column==2 || column==7 ))
    {
        erlaubteZiele.append({row+2,column-1});//qDebug()<<__FILE__<<":"<<__LINE__;
        erlaubteZiele.append({row+2,column+1});//qDebug()<<__FILE__<<":"<<__LINE__;
    }

    //qDebug()<<__FILE__<<":"<<__LINE__;
    if(row==8 && (column==2 || column==7 ))
    {
        erlaubteZiele.append({row-2,column-1});//qDebug()<<__FILE__<<":"<<__LINE__;
        erlaubteZiele.append({row-2,column+1});//qDebug()<<__FILE__<<":"<<__LINE__;
    }
qDebug()<<__FILE__<<":"<<__LINE__<<"Feld("<<row<<","<<column<<") = "<<_figur->utf8Figur.toUtf8()<<" Ziele:"<<erlaubteZiele;
}

QList<QPair<int,int>> Feld::erlaubteZieleErrechnen(int row,int column)
{  qDebug()<<__FILE__<<" : "<<__LINE__<<" erlaubteZieleErrechnen für" <<this->_figur;
    QList<QPair<int,int>> erlaubteFelder;


    erlaubteFelder = this->_figur->erlaubteZieleErrechnen(row, column, this->_figur->utf8Figur);
    return erlaubteFelder;
}
