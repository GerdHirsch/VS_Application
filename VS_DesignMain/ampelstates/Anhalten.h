#ifndef ANHALTEN_H
#define ANHALTEN_H

#include "Betrieb.h"

class StateAmpel;

class Anhalten : public Betrieb 
{
public:
	Anhalten() : Betrieb("Anhalten") {}
private:
    virtual void umschalten(StateAmpel * const This) final;
    virtual void entry(StateAmpel * const This);
};

#endif //ANHALTEN_H
