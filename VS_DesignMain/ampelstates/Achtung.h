#ifndef ACHTUNG_H
#define ACHTUNG_H

#include "../AmpelState.h"

class StateAmpel;

class Achtung : public AmpelState 
{
public:
	Achtung() : AmpelState("Achtung") {}
private:
    virtual void umschalten(StateAmpel * const  This) final;
    virtual void aus(StateAmpel * const This) final;
    virtual void entry(StateAmpel * const  This);
    virtual void warne(StateAmpel * const);
};

#endif //ACHTUNG_H
