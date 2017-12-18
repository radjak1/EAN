#include <iostream>
#include "ean.h"

using namespace std;

Kod_ean::Kod_ean( string str, int r )
{
    rodzaj = r;
    kod = str;
    r_dobry = false;
    k_dobry = false;
    r_sprawdzony = false;
    k_sprawdzony = false;
}

void Kod_ean::sprawdz_rodzaj()
{
    r_sprawdzony = true;

    try
    {
        if( rodzaj > 2 || rodzaj < 1 )
        {            
            string wyjatek = "Zły rodzaj kodu";
            throw wyjatek;
        }
        else if( rodzaj == 1 && ( kod.size() > 13 || kod.size() < 7 || kod.size() == 11 ) )
        {;
            string wyjatek = "Rodzaj kodu nie odpowiada dlugosci kodu";
            throw wyjatek;
        }
        else if( rodzaj == 2 && ( kod.size() > 18 || kod.size() < 12 || kod.size() == 16 ) )
        {            
            string wyjatek = "Rodzaj kodu nie odpowiada dlugosci kodu";
            throw wyjatek;
        }
        else
        {
            r_dobry = true;
        }
    }
    catch( string wyjatek )
    {
        cout << wyjatek << endl;
    }  
}

void Kod_ean::sprawdz_kod()
{
    int suma = 0;
    bool a, b, c, d;
    a = b = c = d = false;
    
    if( r_sprawdzony == false )
    sprawdz_rodzaj();

    k_sprawdzony = true;

    try
    {
        if( kod.size() < 7 )
        {
            string wyjatek = "Kod jest za kótki";
            throw wyjatek;
        }
    
        for( int i = 0; i < 12; ++i )
        {
            if( ( i + 1 ) % 2 == 1 )
            suma += 3 * ( kod[ i ] - '0' );
            else
            suma += kod[ i ] - '0';

            if( i == 5 && ( kod[ 6 ] - '0' ) == ( 10 - ( suma % 10 )))
            a = true;
            else if( i == 6 && ( kod[ 7 ] - '0' ) == ( 10 - ( suma % 10 )))
            b = true;
            else if( i == 10 && ( kod[ 11 ] - '0' ) == ( 10 - ( suma % 10 )))
            c = true;
            else if( i == 11 && ( kod[ 12 ] - '0' ) == ( 10 - ( suma % 10 )))
            d = true;
        }
        
        if( a == false && b == false && c == false && d == false )
        {
            string wyjatek = "Błąd sprawdzania cyfry kontrolnej";
            throw wyjatek;
        }
        else if( rodzaj == 2 && d == true )
        {
            k_dobry = true;
            return;
        }
        else if( rodzaj == 2 && c == true )
        {
            k_dobry = true;
            kod.insert( 0, "0" );     
            return;          
        }
        else if( rodzaj == 1 && b == true )
        {
            k_dobry = true;
            return;
        }
        else if( rodzaj == 1 && a == true )
        {                         
            k_dobry = true;
            kod.insert( 0, "0" );
            return;
        }
        else if( d == true )
        {
	        r_dobry = true;                   
	        rodzaj = 2; 
	        k_dobry = true;
	        string wyjatek = "Zmieniono rodzaj kodu na 2";
	        throw wyjatek;
        }
        else if( c == true )
        {
	        r_dobry = true;                    
	        rodzaj = 2; 
	        k_dobry = true;
	        kod.insert( 0, "0" );     
	        string wyjatek = "Zmieniono rodzaj kodu na 2";
	        throw wyjatek;          
        }
        else if( b == true )
        {
	        r_dobry = true;                   
	        rodzaj = 1; 
	        k_dobry = true;
	        string wyjatek = "Zmieniono rodzaj kodu na 1";
	        throw wyjatek;
        }
        else if( a == true )
        {               
	        r_dobry = true;                    
	        rodzaj = 1;                
	        k_dobry = true;
	        kod.insert( 0, "0" );
	        string wyjatek = "Zmieniono rodzaj kodu na 1";
	        throw wyjatek;
        }    
    }
    catch( string wyjatek )
    {
        cout << wyjatek << endl;        
    }                       
}

void Kod_ean::sprawdzony_kod( string &str )
{   
    if( k_sprawdzony == false )
    sprawdz_kod();
    
    if( k_dobry == true )
    {
        if( rodzaj == 1 )      
        str.assign( kod, 0, 8 );
        else
        str.assign( kod, 0, 13 );        
    }
}

void Kod_ean::wypisz()
{   
    int dlugosc = 0;
    
    if( k_dobry == true && rodzaj == 1 )
    {
        cout << "Poprawny kod: ";
        dlugosc = 8;
    }
    else if( k_dobry == true && rodzaj == 2 )
    {
        cout << "Poprawny kod: ";        
        dlugosc = 13;
    }
    else if( k_sprawdzony == true )
    {
        cout << "Niepoprawny kod: ";
        dlugosc = kod.size();
    }
    else
    {
        cout << "Niesprawdzony kod: ";
        dlugosc = kod.size();
    }
    
    for( int i = 0; i < dlugosc; ++i )
    cout << kod[ i ];
    
    cout << endl;
}
