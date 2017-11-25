#ifndef AUS_H
#define AUS_H

#include "../AmpelState.h"

class StateAmpel;

class Aus : public AmpelState 
{
public:
	Aus() : AmpelState("Aus") {}
private:
    virtual void aus(StateAmpel * const This);
    virtual void entry(StateAmpel * const This);
};

#endif //AUS_H
