#ifndef FELD_H
#define FELD_H

#include <QString>
#include <QList>
#include <QPair>

#include "figur.h"
#include "bauer.h"
#include "turm.h"
#include "lauefer.h"
#include "springer.h"
#include "dame.h"
#include "koenig.h"
#include "nofigur.h"

class Feld
{
public:
    Feld();
    Feld(int,int);
    QString figur;
    Figur* _figur;
    QList<QPair<int,int>> erlaubteZiele; //Sammlung der möglichen Felder(row,column)
    QList<QPair<int,int>> erlaubteZieleErrechnen(int,int);

};

#endif // FELD_H
