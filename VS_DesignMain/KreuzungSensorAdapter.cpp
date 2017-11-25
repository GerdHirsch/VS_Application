#include "KreuzungSensorAdapter.h"

void KreuzungSensorAdapter::trigger(unsigned long)
{
	kreuzung.einfahrtGewaehren(); 
}
