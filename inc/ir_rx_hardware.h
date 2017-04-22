#ifndef __IR_RX_HARDWARE_H__
#define __IR_RX_HARDWARE_H__
#include <stdint.h>

class IRRXHardware {
public:
    IRRXHardware() {};

    virtual void init() {};

    virtual bool receive(uint32_t* received) {};
};

#endif //__IR_RX_HARDWARE_H__
