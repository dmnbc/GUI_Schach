#ifndef KOENIG_H
#define KOENIG_H

#include "figur.h"
#include "dame.h"

class Koenig : public Figur
{
public:
    Koenig();
    Koenig(QString);
    QList<QPair<int,int>> erlaubteZieleErrechnen(int, int, QString);
};

#endif // KOENIG_H
