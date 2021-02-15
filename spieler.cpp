#include "spieler.h"

Spieler::Spieler(const string& name, const int& transfersumme, const Position& position) : name{name}, transfersumme{transfersumme}, position{position}
{
    if(name.empty() || transfersumme<10 || transfersumme>500) throw runtime_error("Error");
}

bool Spieler::operator==(const Spieler& n) const
{
    return (name == n.name);
}


ostream& operator <<(ostream& os, const Spieler& sp)
{
    return os<< "[" << sp.name << ", " << sp.transfersumme << " Mio Euro, " << positionsnamen.at(static_cast<int>(sp.position)) << "]";
}


//Zusatz Punkte:

Position Spieler::get_Position()const
{
    return this->position;
}
