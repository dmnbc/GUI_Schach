#ifndef BAUER_H
#define BAUER_H
#include "figur.h"

class Bauer : public Figur
{
public:
    Bauer();
    Bauer(QString);
    QList<QPair<int,int>> erlaubteZieleErrechnen(int,int,QString);
};

#endif // BAUER_H
