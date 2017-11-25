#include <iostream>
using namespace std;

#include "MediterraneanStates.h"
#include "../ampelstates/MediterraneanStartVorbereiten.h"

MediterraneanStates::MediterraneanStates() : CentralEuropeanStates()
{
	std::cout << "MediterraneanStates()"  << std::endl;
}

void MediterraneanStates::create()
{
	if(lnkTheFactory == 0)
	{
		static MediterraneanStates stateFactory;
		std::cout << "MediterraneanStates::create() Created MediterraneanStates Factory" << std::endl;
	}
	else
	{
		std::cout << "MediterraneanStates::create() A StateFactory already exists..." << std::endl;
	}
}

AmpelState* MediterraneanStates::getState(Key key)
{
	AmpelState* retVal = StateFactory::getState(key);
	if(retVal == 0)
	{
		if(key == AmpelState::STARTVORBEREITEN)
		{
			cout << "MediterraneanStartVorbereiten" << endl;
			retVal = new MediterraneanStartVorbereiten();
			states[key] = retVal;
		}
		else
		{
			retVal = CentralEuropeanStates::getState(key);
		}
	}
	return retVal;
}
