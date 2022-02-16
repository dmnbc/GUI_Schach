#ifndef TURM_H
#define TURM_H
#include "figur.h"


class Turm : public Figur
{
public:
    Turm();
    Turm(QString);
    QList<QPair<int,int>> erlaubteZieleErrechnen(int,int,QString);
};

#endif // TURM_H
