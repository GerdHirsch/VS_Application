/* Generated by Together */

#ifndef LAMPE_H
#define LAMPE_H

/**
 * @interface 
 */
class Lampe {
public:

    virtual void aus() =0;

    virtual void ein() =0;

    virtual bool isAn() =0;

    virtual ~Lampe() = 0;
};
inline
Lampe::~Lampe(){}
#endif //LAMPE_H