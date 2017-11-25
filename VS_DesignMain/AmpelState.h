#ifndef AMPELSTATE_H
#define AMPELSTATE_H

#include <string>

#include "StateAmpel.h"
class StateAmpel;

/**
 * Responsiblity: repr�sentiert abstrakt einen Zustand einer Ampel.
 * Die Ampel und der abstrakte AmpelState sind jeweils friend deklariert.
 * Die Ampel ben�tigt den Zugriff auf die Operation
 * AmpelState::fireTransition(Ampel * const This, AmpelState* state)
 * zur Initialisierung im Konstruktor.
 * Der AmpelState stellt den abgeleiteten State Klassen die
 * protected KlassenOperationen fireTransition(...) und
 * schalteLampen(....)  zur Verf�gung. Diese manipulieren die als
 * Parameter �bergebene Ampel. Damit ist das OCP gew�hrleistet,
 * neue States k�nnen hinzugef�gt werden ohne den vorhandenen Code zu �ndern.
 * Das InformationHidding wird dabei nicht verletzt, da nur die von
 * AmpelState abgeleiteten Klassen die protected Operationen verwenden
 * k�nnen, von aussen k�nnen die Operationen nicht verwendet werden.
 */
class AmpelState 
{
public:
	enum StateName { AUS, STEHEN, ANHALTEN, STARTVORBEREITEN, FAHREN, ACHTUNG };
	virtual ~AmpelState();
protected:
	AmpelState(const std::string& name);
	/** Interface f�r die Substates */
	static AmpelState* getState(StateName key);
    static void fireTransition(StateAmpel * const This, AmpelState * const state);
    static void schalteLampen(StateAmpel * const This, bool rot, bool gelb, bool gruen);
	const std::string& getName() { return name; }
private:
	std::string name;
    virtual void entry(StateAmpel * const This)=0;
//    virtual void doActivity(StateAmpel * const This) = 0;
//    virtual void exit(StateAmpel * const This) = 0;

	friend class StateAmpel;
	/** Interface f�r die Ampel */
	virtual void umschalten(StateAmpel * const This);
	/** Interface f�r die Ampel */
    virtual void aus(StateAmpel * const This);
	/** Interface f�r die Ampel */
    virtual void warne(StateAmpel * const This); // final;
};

inline
void AmpelState::schalteLampen(StateAmpel * const This, bool rot, bool gelb, bool gruen)
{
    This->setLights(rot, gelb, gruen);
}
#endif //AMPELSTATE_H
