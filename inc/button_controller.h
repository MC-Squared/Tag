#ifndef __BUTTON_CONTROLLER_H__
#define __BUTTON_CONTROLLER_H__

#include "button_hardware.h"

class ButtonController {
public:
    ButtonController(ButtonHardware* buttons);

    void init();

    void run();

    void interrupt();

private:
    ButtonHardware* m_buttons;
};

#endif //__BUTTON_CONTROLLER_H__
