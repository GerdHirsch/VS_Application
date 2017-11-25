#include <iostream>
#include <Windows.h>

#include "Verkehrssteuerung.h"

#include "CentralEuropeanConfiguration.h"
#include "MediterraneanConfiguration.h"


using namespace std;
using SensorHersteller::Sensor;

int main()
{
	{
		cout << "***** VerkehrssteuerungDesign Demo *****" << endl << endl;
		cout << "====== Initialisiere...======" << endl;
		CentralEuropeanConfiguration::create();
		//MediterraneanConfiguration::create();
		VerkehrssteuerungsFactory* factory = VerkehrssteuerungsFactory::getFactory();

		cout << "====== Initialisiert ========" << endl << endl;

		cout << "===== main() Verkehrssteuerung erzeugen =====" << endl;
		Verkehrssteuerung verkehrssteuerung(factory);


		cout << endl << "===== main() Verkehrssteuerung in Betrieb nehmen =====" << endl;
		verkehrssteuerung.inBetriebNehmen();

		cout << endl << "===== main() Sensorsignal simulieren =====" << endl;
		verkehrssteuerung.simulateSensorSignal();

		cout << endl << "===== main() Verkehrssteuerung ausser Betrieb nehmen =====" << endl;
		verkehrssteuerung.ausserBetriebNehmen();
	
		cout << endl << "===== main() Verkehrssteuerung in Betrieb nehmen =====" << endl;
		verkehrssteuerung.inBetriebNehmen();
	
		cout << endl << "===== main() Hardware-Defekt simulieren =====" << endl;
		verkehrssteuerung.simulateHardwareDefect();
	}
	cout << endl << "===== end main() Sleep(2000) =====" << endl;
	Sleep(2000);

	return 0;
}

