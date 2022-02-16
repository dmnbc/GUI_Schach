#ifndef FIGUR_H
#define FIGUR_H

#include <QDebug>
#include <QString>
#include <array>

class Figur
{
public:
    Figur();
    Figur(QString);
    QString utf8Figur;
    virtual QList<QPair<int,int>> erlaubteZieleErrechnen(int, int, QString);
    static bool is_white(QString);
    static bool is_same_color(Figur*, Figur*);

};

#endif // FIGUR_H
