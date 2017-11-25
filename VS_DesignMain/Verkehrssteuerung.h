#ifndef VERKEHRSSTEUERUNG_H
#define VERKEHRSSTEUERUNG_H
#include <memory>
#include "MakrosStdMigration.h"

//forward declarations
class Kreuzung;
class KreuzungSensorAdapter;
class Ampel;
class Lampe;

namespace SensorHersteller{
	template<class ObserverPolicy> class Sensor;
	class ListenerSingleRawPointerPolicy;
}
namespace SH = SensorHersteller;

class VerkehrssteuerungsFactory;

/* Responsibility: 
 * Erzeugt und zerstört die Objekte
 * nimmt die Anlage in und ausser Betrieb
 * verwaltet Hardware Errors (defektBearbeiten)
 */
class Verkehrssteuerung
{
public:
	Verkehrssteuerung(VerkehrssteuerungsFactory const*const theFactory);
	~Verkehrssteuerung();

	void inBetriebNehmen();

	void ausserBetriebNehmen();

	void defektBearbeiten();

	void simulateSensorSignal();

	void simulateHardwareDefect();

private:
	void warten(int ms);
	void wartungsdienstInformieren();

	//Objekte werden mit new erzeugt und
	//automatisch vom Destruktor von SmartPointer zerstört
	SmartPointer< SH::Sensor<SH::ListenerSingleRawPointerPolicy> > sensor;
	SmartPointer<Kreuzung> kreuzung;
	SmartPointer<KreuzungSensorAdapter> adapter;

	SmartPointer<Ampel> a1;
	SmartPointer<Lampe> a1Rot;
	SmartPointer<Lampe> a1Gelb;
	SmartPointer<Lampe> a1Gruen;

	SmartPointer<Ampel> a2;
	SmartPointer<Lampe> a2Rot;
	SmartPointer<Lampe> a2Gelb;
	SmartPointer<Lampe> a2Gruen;

	SmartPointer<Ampel> a3;
	SmartPointer<Lampe> a3Rot;
	SmartPointer<Lampe> a3Gelb;
	SmartPointer<Lampe> a3Gruen;

	//für EA Association
	//Sensor *lnkSensor;
	//Kreuzung* lnkKreuzung;
	//KreuzungSensorAdapter* lnkAdapter;
	//End EA Association
};
#endif //VERKEHRSSTEUERUNG_H
