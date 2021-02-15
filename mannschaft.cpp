#include "spieler.h"
#include "mannschaft.h"

Mannschaft::Mannschaft(const string& nameMannschaft, const vector<Spieler>& liste) : nameMannschaft{nameMannschaft}, liste{liste}
{
    if(nameMannschaft.empty()) throw runtime_error("Error!");

    for(size_t i = 0; i<liste.size(); i++)
    {
        for(size_t j = i+1; j<liste.size(); j++)
        {
            if(liste.at(i)==liste.at(j)) throw runtime_error("Error!");
        }
    }
}

vector<Spieler> Mannschaft::engagieren(const vector<Spieler>& v)
{
    vector<Spieler>entfernt;
    bool temp = true;
    for(size_t i = 0; i<v.size(); i++)
    {
        temp = false;
        for(size_t j = 0; j<liste.size(); j++)
        {
            if(v.at(i)==liste.at(j))
            {
                entfernt.push_back(v.at(i));
                temp = true;
                break;
            }
        }
        if(!temp)
        {
            liste.push_back(v.at(i));
        }
    }
    return entfernt;
}

ostream& operator<<(ostream& o, const Mannschaft& mann){
    //[Name, {Liste der Spieler}]
    o<< "[" << mann.nameMannschaft << ", {";
    for(size_t i = 0; i<mann.liste.size(); i++)
    {
        o << mann.liste.at(i);
        if(i!=mann.liste.size()-1) o << ", ";
    }
    return o << "}]";
}

//Zusatz Punkte:

/*string Mannschaft::aufstellung() const
{
    Loesung nur fuer Linux:
    int x = 0;
    int y = 0;
    int z = 0;
    for(size_t i = 0; i<liste.size(); i++)
    {
        if(liste.at(i).get_Position()==Position::Abwehr) x++;
        if(liste.at(i).get_Position()==Position::Sturm) y++;
        if(liste.at(i).get_Position()==Position::Sturm) z++;
    }

    if(x+y+z!=10) throw runtime_error("Error!");
    string gesamt = "";
    gesamt += to_string(x) + "-" << to_string(y) << "-" << to_string(z);
    return gesamt;

}*/

/*vector<Spieler> Mannschaft::entlassen(vector<Position> pos) //Dekomentieren fuer 15 Zusatzpunkte
{
    vector<Spieler>entfernt;
    vector<Spieler>temp;
    bool found = false;
    for(size_t i = 0; i<liste.size(); i++)
    {
        for(size_t j = 0; j<pos.size(); j++)
        {
            if(liste.at(i).get_Position()==pos.at(j))
            {
                entfernt.push_back(liste.at(i));
                found = true;
                break;
            }
        }
        if(!found) temp.push_back(liste.at(i));
    }
    liste.clear();
    for(size_t i = 0; i<temp.size(); i++)
    {
        liste.push_back(temp.at(i));
    }
    return entfernt;
}*/
