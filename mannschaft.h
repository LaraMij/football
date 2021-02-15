#ifndef MANNSCHAFT_H
#define MANNSCHAFT_H

#include "spieler.h"

class Mannschaft
{

    private:
        string nameMannschaft;
        vector<Spieler>liste;

    public:
        Mannschaft(const string& nameMannschaft, const vector<Spieler>& liste = vector<Spieler>());
        vector<Spieler> engagieren(const vector<Spieler>&);
        friend ostream& operator<<(ostream&, const Mannschaft&);

        //Zusatz Punkte:
        //string aufstellung() const; //Nur fuer Linux(10 Zusatz Punkte)!!!

        //vector<Spieler> entlassen(vector<Position>); //Fuer 15 Zusatzpunkte!!!
};

#endif // MANNSCHAFT_H
