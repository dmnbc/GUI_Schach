#ifndef SPRINGER_H
#define SPRINGER_H
#include "figur.h"

class Springer : public Figur
{
public:
    Springer();
    Springer(QString);
    QList<QPair<int,int>> erlaubteZieleErrechnen(int,int,QString);
};

#endif // SPRINGER_H
