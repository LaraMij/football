#ifndef SPIELER_H
#define SPIELER_H

#include<iostream>
#include<vector>
#include<string>
#include<sstream>

using namespace std;

enum class Position {Tor, Abwehr, Mitte, Sturm};
const vector<string> positionsnamen{"Tor", "Abwehr", "Mitte", "Sturm"};


class Spieler
{
    private:
        string name;
        int transfersumme;
        Position position;


    public:
        Spieler(const string& name, const int& transfersumme, const Position& position = Position::Tor);
        bool operator==(const Spieler&) const;
        friend ostream& operator<<(ostream&, const Spieler&);

        //Zusatz Punkte:
        Position get_Position() const;
};

#endif // SPIELER_H
