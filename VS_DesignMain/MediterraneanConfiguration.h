#ifndef MEDITERRANEANCONFIGURATION_H
#define MEDITERRANEANCONFIGURATION_H

#include <stdexcept>

#include "VerkehrssteuerungsFactory.h"

class MediterraneanConfiguration : public VerkehrssteuerungsFactory
{
public:
	// Enhanced Singleton
	static void create();
	virtual SmartPointer<Lampe> createLampe(std::string const& configInfo) const;
protected:
	MediterraneanConfiguration();
};

#endif //MEDITERRANEANCONFIGURATION_H
