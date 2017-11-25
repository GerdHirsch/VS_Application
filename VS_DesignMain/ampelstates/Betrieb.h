#ifndef BETRIEB_H
#define BETRIEB_H

#include "../AmpelState.h"

class StateAmpel;

class Betrieb : public AmpelState 
{
public:
	Betrieb(const std::string& name) : AmpelState(name) {}

};

#endif //BETRIEB_H
