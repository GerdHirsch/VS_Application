#include <iostream>
#include <string>
//#include <memory>
// ersetzt durch memory C++11
//#include <boost/shared_ptr.hpp>

#include "CanLampe.h"
#include "statefactory/MediterraneanStates.h"
#include "MediterraneanConfiguration.h"

using namespace std;

MediterraneanConfiguration::MediterraneanConfiguration()
{
	cout << "MediterraneanConfiguration()" << endl;
}

void MediterraneanConfiguration::create() // throw(logic_error)
{
	if(theFactory == 0)
	{
		cout << "MediterraneanConfiguration::create() erzeuge MediterraneanStates" << endl;
		MediterraneanStates::create();
		cout << "MediterraneanConfiguration::create() MediterraneanStates erzeugt" << endl;
		static MediterraneanConfiguration factory;
	}
	else
	{
		throw logic_error("MediterraneanConfiguration: VerkehrssteuerungsFactory can be created only once!");
	}
}

SmartPointer<Lampe> MediterraneanConfiguration::createLampe(const std::string& configInfo) const
{
	return SmartPointer<Lampe>(new CanLampe(configInfo));
}



