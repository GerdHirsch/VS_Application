#include <iostream>
using namespace std;

#include "CentralEuropeanStates.h"
#include "../ampelstates/Aus.h"
#include "../ampelstates/Achtung.h"
#include "../ampelstates/Stehen.h"
#include "../ampelstates/StartVorbereiten.h"
#include "../ampelstates/Fahren.h"
#include "../ampelstates/Anhalten.h"


void CentralEuropeanStates::create() //throw(std::logic_error)
{
	if(lnkTheFactory == 0)
	{
		static CentralEuropeanStates stateFactory;
		std::cout << "CentralEuropeanStates::create() Created CentralEuropeanStates Factory" << std::endl;
	}
	else
	{
		std::cout << "CentralEuropeanStates::create() A StateFactory already exists..." << std::endl;
	}
}

CentralEuropeanStates::CentralEuropeanStates() : StateFactory()
{
	std::cout << "CentralEuropeanStates()"  << std::endl;
}

CentralEuropeanStates::~CentralEuropeanStates()
{

}

AmpelState* CentralEuropeanStates::getState(Key key)
{
	AmpelState* retVal = StateFactory::getState(key);
	if(retVal == 0)
	{
		if(key == AmpelState::ACHTUNG)
		{
			retVal = new Achtung();			
		}
		else if(key == AmpelState::ANHALTEN)
		{
			retVal = new Anhalten();
		}
		else if(key == AmpelState::AUS)
		{
			retVal = new Aus();
		}
		else if(key == AmpelState::FAHREN)
		{
			retVal = new Fahren();
		}
		else if(key == AmpelState::STARTVORBEREITEN)
		{
			cout << "CentralEurope StartVorbereiten" << endl;

			retVal = new StartVorbereiten();
		}
		else if(key == AmpelState::STEHEN)
		{
			retVal = new Stehen();
		}
		states[key] = retVal;
	}
	return retVal;
}
