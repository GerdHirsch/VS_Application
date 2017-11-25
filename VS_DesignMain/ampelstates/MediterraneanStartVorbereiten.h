#ifndef MEDITERRANEANSTARTVORBEREITEN_H
#define MEDITERRANEANSTARTVORBEREITEN_H

#include "StartVorbereiten.h"

class StateAmpel;

class MediterraneanStartVorbereiten : public StartVorbereiten 
{
public:
	MediterraneanStartVorbereiten() : StartVorbereiten("MediterraneanStartVorbereiten") {}
private:
    virtual void entry(StateAmpel * const This);
};

#endif //MEDITERRANEANSTARTVORBEREITEN_H
