#include <iostream>
#include <string>
//#include <memory>

// ersetzt durch memory C++11
//#include <boost/shared_ptr.hpp>

#include "IPLampe.h"

#include "statefactory/CentralEuropeanStates.h"
#include "CentralEuropeanConfiguration.h"

using namespace std;

CentralEuropeanConfiguration::CentralEuropeanConfiguration()
{
	cout << "CentralEuropeanConfiguration()" << endl;
}

void CentralEuropeanConfiguration::create()
{
	if(theFactory == 0)
	{
		cout << "CentralEuropeanConfiguration::create() erzeuge CentralEuropeanStates" << endl;
		CentralEuropeanStates::create();

		cout << "CentralEuropeanConfiguration::create() CentralEuropeanStates erzeugt" << endl;
		static CentralEuropeanConfiguration factory;
	}
	else
	{
		throw logic_error("CentralEuropeanConfiguration: VerkehrssteuerungsFactory can be created only once!");
	}
}

SmartPointer<Lampe> CentralEuropeanConfiguration::createLampe(const std::string& configInfo) const
{
	return SmartPointer<Lampe>(new IPLampe(configInfo));
}
