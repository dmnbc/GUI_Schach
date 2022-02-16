#ifndef LAUEFER_H
#define LAUEFER_H
#include "figur.h"


class Lauefer : public Figur
{
public:
    Lauefer();
    Lauefer(QString);
    QList<QPair<int,int>> erlaubteZieleErrechnen(int, int, QString);
};

#endif // LAUEFER_H
