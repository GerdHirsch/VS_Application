/* Generated by Together */

#include "Fahren.h"
//#include "../StateFactory.h"

void Fahren::umschalten(StateAmpel * const This){
	fireTransition(This, getState(ANHALTEN));
}
void Fahren::entry(StateAmpel * const This){
    schalteLampen(This, false, false, true);
}
