#ifndef MEDITERANIANSTATES_H
#define MEDITERANIANSTATES_H

#include <stdexcept>

#include "CentralEuropeanStates.h"

class AmpelState;

class MediterraneanStates : public CentralEuropeanStates
{
public:
	static void create();
    virtual AmpelState * getState(Key key);
	MediterraneanStates();
};

#endif //MEDITERANIANSTATES_H
