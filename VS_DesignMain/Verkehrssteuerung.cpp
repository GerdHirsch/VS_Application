#include <iostream>
#include <string>
#include <Windows.h>


#include <Kreuzung/Ampel.h>

#include "VerkehrssteuerungsFactory.h"
#include "Verkehrssteuerung.h"

#include <Kreuzung/Kreuzung.h>
#include <Sensor/ListenerSingleRawPointer.h>
#include <Sensor/Sensor.h>

#include <VS/Lampe.h>
#include "KreuzungSensorAdapter.h"

using namespace std;

Verkehrssteuerung::~Verkehrssteuerung(){
	std::cout << "Verkehrssteuerung::~Verkehrssteuerung()" << std::endl;
}
Verkehrssteuerung::Verkehrssteuerung(VerkehrssteuerungsFactory const*const factory)
{

	//Factory verwenden
	a1Rot = factory->createLampe("a1.rot"); // hier wird auch die Ampel benötigt!
	a1Gelb = factory->createLampe("a1.gelb");
	a1Gruen = factory->createLampe("a1.gruen");
	a1 = factory->createAmpel("a1", *a1Rot.get(), *a1Gelb.get(), *a1Gruen.get() );

	a2Rot = factory->createLampe("a2.rot");
	a2Gelb = factory->createLampe("a2.gelb");
	a2Gruen = factory->createLampe("a2.gruen");
	a2 = factory->createAmpel("a2", *a2Rot.get(), *a2Gelb.get(), *a2Gruen.get() );

	a3Rot = factory->createLampe("a3.rot");
	a3Gelb = factory->createLampe("a3.gelb");
	a3Gruen = factory->createLampe("a3.gruen");
	a3 = factory->createAmpel("a3", *a3Rot.get(), *a3Gelb.get(), *a3Gruen.get() );

	kreuzung = factory->createKreuzung(*a1.get(), *a2.get(), *a3.get() );

	sensor = factory->createSensor();

	adapter = SmartPointer<KreuzungSensorAdapter>(
				new KreuzungSensorAdapter(*kreuzung.get())
													);

	sensor->addSensorListener( adapter.get() );
}

void Verkehrssteuerung::inBetriebNehmen()
{
	//Betrieb starten
	kreuzung->blinke();
	warten(200);
	kreuzung->ein();
}
void Verkehrssteuerung::warten(int ms)
{
	cout << "===> Verkehrssteuerung::warten(" << ms << "ms)" << endl;
	Sleep(ms);
}
void Verkehrssteuerung::ausserBetriebNehmen()
{
	//Bzw. einfach ordentlich "herunterfahren"
	cout << "===> Verkehrssteuerung:ausserBetriebNehmen()" << endl;
	kreuzung->blinke();
	warten(200);
	kreuzung->aus();
}

void Verkehrssteuerung::defektBearbeiten()
{
	cout << "===> Verkehrssteuerung:defektBearbeiten()" << endl;
	kreuzung->defect();
	wartungsdienstInformieren();
	warten(200);
	kreuzung->aus();
}
void Verkehrssteuerung::wartungsdienstInformieren()
{
	cout << "===> E-Mail an Wartungsdienst versenden" << endl;
}

void Verkehrssteuerung::simulateSensorSignal()
{
	sensor->externalSignal();
}

void Verkehrssteuerung::simulateHardwareDefect()
{
	defektBearbeiten();
}
