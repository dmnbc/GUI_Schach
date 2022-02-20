#ifndef XML_AUSTAUSCH_H
#define XML_AUSTAUSCH_H

#include <QtXml>
#include <QTextStream>
#include "feld.h"


class XML_Austausch
{
public:
    XML_Austausch();  // ctor
    bool zug_aufzeichnen();  // Einzug
    bool zug_ergaenzen(QString filename, std::array<std::array<Feld,10>,10> stellung);    // weitere Züge zur XML hinzuzufügen Update mit DOM
};

#endif // XML_AUSTAUSCH_H
