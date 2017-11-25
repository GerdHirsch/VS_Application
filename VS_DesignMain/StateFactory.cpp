#include <iostream>
#include <stdexcept>
#include <string>
#include <algorithm>
using namespace std;

#include "StateFactory.h"
 StateFactory::~StateFactory()
 {
	 for_each(states.begin(), states.end(), deletor);
	 states.clear();
 }
 void StateFactory::deletor(pair<Key, AmpelState*> state)
 {
	 delete state.second;
 }
StateFactory* StateFactory::getFactory()
{
	if(lnkTheFactory == 0)
	{
		throw std::logic_error("StateFactory not initialized");
	}
    return lnkTheFactory;
}

StateFactory* StateFactory::lnkTheFactory = 0;

StateFactory::StateFactory()
{
	std::cout << "StateFactory()"  << std::endl;
	if(lnkTheFactory != 0)
	{
		throw std::logic_error("StateFactory can only be created once!");
	}
    lnkTheFactory = this;
}

AmpelState* StateFactory::getState(Key key)
{
	return states[key];
}
