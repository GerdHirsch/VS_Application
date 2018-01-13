#ifndef IPLAMPE_H
#define IPLAMPE_H

#include <string>

#include <VS/Lampe.h>

class IPLampe : public Lampe {
public:

	IPLampe(std::string ipAdress);

    void ein();
    void aus();
    bool isAn();
private:
    bool an;
	std::string ipAdress;
};
#endif //IPLAMPE_H
