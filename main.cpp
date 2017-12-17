/* W przypadku gdzie rodzaj kodu jest zły i kod ma długość 12 / 13 
( kod EAN-8 + Add-on 5-cyfrowy lub EAN-13 ) oraz występyje zgodność 
dla cyfry kontrolnej w EAN-8 i EAN-13 to program preferuje dłuższy kod EAN-13. 

Funkcja sprawdzajaca to void sprawdz_kod()  linia 82 */

#include <iostream>
#include "ean.h"

using namespace std;

class Kod_ean;

int main()
{
    string kod_dzialajacy;
    Kod_ean k( "6385073", 3 );

    //k.sprawdz_rodzaj();
    //k.sprawdz_kod();
    //k.wypisz();
    
    k.sprawdzony_kod( kod_dzialajacy );
    cout << kod_dzialajacy << endl;
    
    k.~Kod_ean();
    
    return 0;
}
