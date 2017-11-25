#ifndef CENTRALEUROPEANSTATES_H
#define CENTRALEUROPEANSTATES_H

#include <stdexcept>

#include "../StateFactory.h"

class AmpelState;

class CentralEuropeanStates : public StateFactory 
{
public:
	static void create(); //throw(std::logic_error);

    CentralEuropeanStates();

    virtual ~CentralEuropeanStates();

	virtual AmpelState* getState(Key key);
};

#endif //CENTRALEUROPEANSTATES_H
