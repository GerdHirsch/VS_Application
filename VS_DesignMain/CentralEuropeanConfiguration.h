#ifndef CENTRALEUROPEANCONFIGURATION_H
#define CENTRALEUROPEANCONFIGURATION_H

#include <stdexcept>

#include "VerkehrssteuerungsFactory.h"

class CentralEuropeanConfiguration : public VerkehrssteuerungsFactory
{
public:
	// Enhanced Singleton
	static void create();
	virtual SmartPointer<Lampe> createLampe(std::string const& configInfo) const;
protected:
	CentralEuropeanConfiguration();
};

#endif //CENTRALEUROPEANCONFIGURATION_H
