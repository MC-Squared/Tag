#ifndef __BUTTON_HARDWARE_H__
#define __BUTTON_HARDWARE_H__
#include <stdint.h>

class ButtonHardware {
public:
    ButtonHardware() {};

    virtual void init(uint8_t gpio) {};

    virtual bool is_pressed() {};
};

#endif //__BUTTON_HARDWARE_H__
