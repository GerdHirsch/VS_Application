/* Generated by Together */

#include "Stehen.h"
#include "../StateFactory.h"

void Stehen::entry(StateAmpel * const This){
    schalteLampen(This, true, false, false);
}
void Stehen::umschalten(StateAmpel * const This){
    fireTransition(This, getState(STARTVORBEREITEN));
}
