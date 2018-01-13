#ifndef CANLAMPE_H
#define CANLAMPE_H

#include <string>

#include <VS/Lampe.h>

class CanLampe : public Lampe 
{
public:
	CanLampe(std::string canAddress);

    void ein();
    void aus();
    bool isAn();
private:
    bool an;
	std::string canAddress;
};

#endif //CANLAMPE_H
