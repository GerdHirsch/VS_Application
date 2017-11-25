#ifndef STATEFACTORY_H
#define STATEFACTORY_H

#include <stdexcept>
#include <map>
#include <string>

#include "AmpelState.h"
//class AmpelState;
//enum AmpelState::StateName;

/**
 * Responsibility: erzeugt und verwaltet die State Objekte (Flyweight GoF).
 * Stellt die einzige Factory über getFactory zur Verfügung (Singleton GoF)
 * Die konkrete Factory wird in der Anwendung erzeugt, der Konstruktor initialisiert die 
 * Klassenvariable theFactory.
 * Von jeder AmpelState Klasse gibt es jeweils nur ein Objekt. 
 * Dieses wird bei der ersten Anforderung mit new erzeugt und in einem Container gespeichert.
 * Der Destruktor zerstört die erzeugten AmpelState Objekte. 
 */
class StateFactory {
public:
	typedef AmpelState::StateName Key;

	virtual ~StateFactory() = 0;

	virtual AmpelState* getState(Key key);

	static StateFactory* getFactory();

protected:
    static StateFactory* lnkTheFactory;
	static void deletor(std::pair<Key, AmpelState*> state);

protected:
	StateFactory();
	std::map<Key, AmpelState*> states;
};

#endif //STATEFACTORY_H
