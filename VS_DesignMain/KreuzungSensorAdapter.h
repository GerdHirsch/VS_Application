#ifndef KREUZUNGSENSORADAPTER_H
#define KREUZUNGSENSORADAPTER_H

#include <Kreuzung/Kreuzung.h>
#include <Sensor/SensorListener.h>
#include <iostream>

using SensorHersteller::SensorListener;

/**
 * Responsibility: leitet die Nachrichten vom Sensor an die Kreuzung weiter und
 * führt notwendige Anpassunge durch
 * Konkreter Partner von Sensor 
 */
class KreuzungSensorAdapter : public SensorListener{
public:
	KreuzungSensorAdapter(Kreuzung& kreuzung) : kreuzung(kreuzung) {}
	~KreuzungSensorAdapter() {
		std::cout << "KreuzungSensorAdapter::~KreuzungSensorAdapter()" << std::endl;
	}
    virtual void trigger(unsigned long time);
private:
	Kreuzung& kreuzung;

};
#endif //KREUZUNGSENSORADAPTER_H
