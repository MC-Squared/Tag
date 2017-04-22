#ifndef __IR_TX_HARDWARE_H__
#define __IR_TX_HARDWARE_H__
#include <stdint.h>

class IRTXHardware {
public:
    IRTXHardware() {};

    virtual void init() {};

    virtual bool send(uint32_t bullet, uint8_t bullet_len) {};
};

#endif //__IR_TX_HARDWARE_H__
