#include "spiel.h"
#include <QDebug>


Spiel::Spiel()
{   // Grundaufstellung berechnen für spielStand
    for(int row = 0; row <10;row++)
    {
        for(int column=0; column <10;column++)
        {
        // Aufruf des ctor von Feld
        qDebug()<<__FILE__<<":"<<__LINE__<<" mit "<<row<<","<<column;
        spielStand.at(row).at(column) = Feld(row,column);
    }
  }
}
