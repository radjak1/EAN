#include <iostream>

using namespace std;

class Kod_ean
{
    int rodzaj;
    string kod;
    bool r_dobry;
    bool k_dobry;
    bool r_sprawdzony;
    bool k_sprawdzony;
    
    public:
    Kod_ean( string str = "11111115" , int r = 1 );
    void sprawdz_rodzaj();
    void sprawdz_kod();
    void wypisz();
    void sprawdzony_kod( string & );
};
