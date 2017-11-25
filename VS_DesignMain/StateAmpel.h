#ifndef STATEAMPEL_H
#define STATEAMPEL_H

// nur für Ausgabezwecke
#include <iostream>

#include <Kreuzung/Ampel.h>
#include "Lampe.h"
class AmpelState;

//#include "AmpelState.h"

#include "IllegalStateException.h"

class Lampe;

/**
 * Responsibility: steuert die Lampen
 * Die Klasse ist einerseits konkret, sie hat konkrete Beziehungen zu ihren Lampen,
 * andererseits abstrakt, weil ihre Methoden an abstrakte Methoden eines AmpelState Objekts 
 * weitergeleitet werden. Dies ist der HotSpot, um benutzerdefiniertes Verhalten fest zu legen.
 * Ihr Protokoll wird durch eine Protokoll StateMachine definiert.
 */
class StateAmpel : public Ampel {
public:
    StateAmpel(const std::string& name, Lampe& rot, Lampe& gelb, Lampe& gruen);
    virtual ~StateAmpel(){ std::cout << "StateAmpel::~StateAmpel()" << std::endl;}

    virtual void aus();// throw(IllegalStateException);

    virtual void warne();

    virtual void umschalten();// throw(IllegalStateException);

	const std::string& getName() { return name; }
private:
	std::string name;
    Lampe* rot;
    Lampe* gelb;
    Lampe* gruen;
 
    AmpelState* currentState;
    void setLights(bool red, bool yellow, bool green);
    friend class AmpelState;
};

#endif //STATEAMPEL_H
