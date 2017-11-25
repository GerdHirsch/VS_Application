#ifndef VERKEHRSSTEUERUNGSFACTORY_H
#define VERKEHRSSTEUERUNGSFACTORY_H

#include <iostream>
#include <string>
#include <memory>
// ersetzt durch memory C++11
//#include <boost/shared_ptr.hpp>
#include <stdexcept>
#include "MakrosStdMigration.h"

//forward declarations
class Lampe;
class Ampel;
class Kreuzung;

namespace SensorHersteller{
	template<class ObserverPolicy> class Sensor;
	class ListenerSingleRawPointerPolicy;
}
namespace SH = SensorHersteller;

class VerkehrssteuerungsFactory
{
public:
	// Singleton
	static VerkehrssteuerungsFactory* getFactory();

	// AbstractFactory
	virtual SmartPointer<Lampe> createLampe(std::string const& configInfo) const = 0;
	virtual SmartPointer<Ampel> createAmpel(std::string const& name,
												Lampe& rot,
												Lampe& gelb,
												Lampe& gruen) const;
	virtual SmartPointer<Kreuzung> createKreuzung(Ampel& a1, Ampel& a2, Ampel& a3) const;

	typedef SH::Sensor< SH::ListenerSingleRawPointerPolicy > Sensor;
	virtual SmartPointer<Sensor> createSensor() const;

protected:
	// Singleton
	VerkehrssteuerungsFactory();
	static VerkehrssteuerungsFactory* theFactory;
};
#endif //VERKEHRSSTEUERUNGSFACTORY_H
