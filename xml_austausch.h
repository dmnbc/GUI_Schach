#ifndef XML_AUSTAUSCH_H
#define XML_AUSTAUSCH_H

#include <QtXml>
#include <QTextStream>


class XML_Austausch
{
public:
    XML_Austausch();  // ctor
    bool zug_aufzeichnen();  // Einzug
    bool zug_ergaenzen(QString stellung);    // weitere Züge zur XML hinzuzufügen Update mit DOM
};

#endif // XML_AUSTAUSCH_H
