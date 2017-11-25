#ifndef STEHEN_H
#define STEHEN_H

#include "Betrieb.h"

class StateAmpel;

class Stehen : public Betrieb 
{
public:
	Stehen() : Betrieb("Stehen") {}
private:
    virtual void umschalten(StateAmpel * const This) final;
    virtual void entry(StateAmpel * const This);
};

#endif //STEHEN_H
