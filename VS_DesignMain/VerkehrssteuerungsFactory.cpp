
#include "VerkehrssteuerungsFactory.h"
#include <Sensor.h>
#include <ListenerSingleRawPointer.h>
#include "StateAmpel.h"

#include <Sensor.h>
#include <Kreuzung/Ampel.h>
#include <Kreuzung/Kreuzung.h>

#include "Lampe.h"

//=====================================================================
// Abstract Factory
//=====================================================================
SmartPointer<Ampel> VerkehrssteuerungsFactory::createAmpel(const std::string& name, Lampe& rot, Lampe& gelb, Lampe& gruen) const
{
	return SmartPointer<Ampel>(new StateAmpel(name, rot, gelb, gruen));
}

SmartPointer<Kreuzung> VerkehrssteuerungsFactory::createKreuzung(Ampel& a1, Ampel& a2, Ampel& a3) const
{
	return SmartPointer<Kreuzung>(new Kreuzung(a1, a2, a3));
}

SmartPointer<SH::Sensor<SH::ListenerSingleRawPointerPolicy> > VerkehrssteuerungsFactory::createSensor() const
{
	typedef SH::Sensor<SH::ListenerSingleRawPointerPolicy> Sensor;
	return SmartPointer<Sensor>(new Sensor());
}
//=====================================================================
// Singleton
//=====================================================================
VerkehrssteuerungsFactory* VerkehrssteuerungsFactory::theFactory = 0;

VerkehrssteuerungsFactory* VerkehrssteuerungsFactory::getFactory()
{
	if(theFactory == 0)
	{
		throw std::logic_error("VerkehrssteuerungsFactory not initialized");
	}
    return theFactory;
}

VerkehrssteuerungsFactory::VerkehrssteuerungsFactory()
{
	std::cout << "VerkehrssteuerungsFactory()"  << std::endl;
	if(theFactory != 0)
	{
		throw std::logic_error("VerkehrssteuerungsFactory can be created only once!");
	}
    theFactory = this;
}
