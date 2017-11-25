#include <iostream>
using namespace std;

//#include "IllegalStateException.h"
#include <Kreuzung/ProtocolViolationException.h>
#include "AmpelState.h"
#include "StateAmpel.h"
#include "StateFactory.h"

AmpelState::AmpelState(const std::string& name)
	: name(name)
{}


AmpelState::~AmpelState()
{
	cout << "AmpelState::~AmpelState " << name << endl;
}

void AmpelState::umschalten(StateAmpel * const This) //throw(IllegalStateException)
{
    throw ProtocolViolationException("umschalten in State: AUS");
}
void AmpelState::aus(StateAmpel * const This) //throw(IllegalStateException)
{
    throw ProtocolViolationException("aus in Betriebsstate");
}
void AmpelState::warne(StateAmpel * const This){
	AmpelState::fireTransition(This, getState(ACHTUNG));
}

AmpelState* AmpelState::getState(StateName key)
{
	return StateFactory::getFactory()->getState(key);
}

void AmpelState::fireTransition(StateAmpel * const This, AmpelState * const state)
{
	//This->lnkMyState->exit(This);
    This->currentState = state;
	cout << This->getName() << ": " << This->currentState->name << " ";
    This->currentState->entry(This);
	cout << endl;
}


