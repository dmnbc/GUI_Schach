#ifndef NOFIGUR_H
#define NOFIGUR_H
#include <QString>
#include "figur.h"


class NoFigur: public Figur
{
public:
    NoFigur();
    NoFigur(QString);
    QList<QPair<int,int>> erlaubteZieleErrechnen();
};

#endif // NOFIGUR_H
