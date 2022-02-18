#include "xml_austausch.h"

#include <QDebug>

XML_Austausch::XML_Austausch()
{

}

bool XML_Austausch::zug_aufzeichnen()
{
    qDebug()<<__FILE__<<":"<<__LINE__<<"zug_aufzeichnen()";
    return true;
}

bool XML_Austausch::zug_ergaenzen()
{
    qDebug()<<__FILE__<<":"<<__LINE__<<"zug_ergaenzen()";
    return true;
}
