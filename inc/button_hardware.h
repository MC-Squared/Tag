#ifndef __BUTTON_HARDWARE_H__
#define __BUTTON_HARDWARE_H__
#include <stdint.h>

enum button_t {
    BUTTON_NONE     = 0,
    BUTTON_TRIGGER  = 1,
    BUTTON_RELOAD   = 2,
    BUTTON_MODE     = 4
};

class ButtonHardware {
public:
    ButtonHardware() {};

    virtual void init() {};

    //Returns a bitmask of all the currently pressed buttons,
    //represented by enum button_t above.
    virtual uint8_t get_pressed() {};
};

#endif //__BUTTON_HARDWARE_H__
