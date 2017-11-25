#ifndef STARTVORBEREITEN_H
#define STARTVORBEREITEN_H

#include "Betrieb.h"

class StateAmpel;

class StartVorbereiten : public Betrieb 
{
public:
	StartVorbereiten() : Betrieb("StartVorbereiten") {}
	StartVorbereiten(const std::string& name) : Betrieb(name) {}

private:
    virtual void umschalten(StateAmpel * const This) final;
    virtual void entry(StateAmpel * const This);
};

#endif //STARTVORBEREITEN_H
