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

bool XML_Austausch::zug_ergaenzen(QString stellung)
{ // https://thecodeprogram.com/how-to-read-and-write-xml-files-in-qt-c--
    qDebug()<<__FILE__<<":"<<__LINE__<<"zug_ergaenzen()";
    return true;
}
