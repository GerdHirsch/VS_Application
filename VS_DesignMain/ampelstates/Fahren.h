#ifndef FAHREN_H
#define FAHREN_H
#include "Betrieb.h"

class Fahren : public Betrieb 
{
public:
	Fahren() : Betrieb("Fahren") {}
private:
    virtual void umschalten(StateAmpel * const This) final;
    virtual void entry(StateAmpel * const This);
};

#endif //FAHREN_H
