#include <iostream>
#include "CanLampe.h"

using namespace std;

CanLampe::CanLampe(string canAddress): an(false), canAddress(canAddress)
{
	cout << "CanLampe(): " << canAddress << endl;
}
void CanLampe::ein(){
    //hier die kommunikation mit der HW-Lampe realisieren
    an = true;
    cout << canAddress << " ";
}
void CanLampe::aus(){
    //hier die kommunikation mit der HW-Lampe realisieren
    an = false;
    //cout << canAddress << " aus ";
}
bool CanLampe::isAn(){ return an;}
