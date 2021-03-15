// nur für tracing
#include <iostream>

//#include <IllegalStateException.h>
#include "StateAmpel.h"
#include "AmpelState.h"
//#include "StateFactory.h"

using namespace std;

StateAmpel::StateAmpel(const std::string& name, Lampe& rot, Lampe& gelb, Lampe& gruen)
: name(name), rot(&rot),gelb(&gelb),gruen(&gruen)
{	
	cout << "=> StateAmpel::StateAmpel(rot, gelb, gruen)" << endl;
	AmpelState::fireTransition(this, AmpelState::getState(AmpelState::AUS));
}
void StateAmpel::umschalten()
{
	cout << "=> umschalten()" << endl;
	currentState->umschalten(this);
}
void StateAmpel::aus(){
	cout << "=> aus()" << endl;
	currentState->aus(this);
}
void StateAmpel::warne(){
	cout << "=> warne()" << endl;
	currentState->warne(this);
}
void StateAmpel::setLights(bool red, bool yellow, bool green){
	if(red)
		rot->ein();
	else
		rot->aus();

	if(yellow)
		gelb->ein();
	else
		gelb->aus();

	if(green)
		gruen->ein();
	else
		gruen->aus();
}


