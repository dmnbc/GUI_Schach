#ifndef DAME_H
#define DAME_H
#include "figur.h"

class Dame : public Figur
{
public:
    Dame();
    Dame(QString);
    QList<QPair<int,int>> erlaubteZieleErrechnen(int,int,QString);
};

#endif // DAME_H
