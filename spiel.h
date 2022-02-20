#ifndef SPIEL_H
#define SPIEL_H
#include <array>
#include <QString>
#include "feld.h"


class Spiel
{
public:
    Spiel();
    static std::array<std::array<Feld,10>,10> spielStand   ; // static std::map<std::string, Feld> spielStand;
    static QString aufgenommeneFigur;
    static Figur* aufgenommene_Figur;
    static int clicknummer;
    static QPair<int,int> last_even_clickPosition;
    static bool spieler;
    static int zugnummer;
    static QString xmlFile;

};

#endif // SPIEL_H
