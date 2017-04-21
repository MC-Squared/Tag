#ifndef __BUTTON_CONTROLLER_H__
#define __BUTTON_CONTROLLER_H__

#include "base_controller.h"
#include "button_hardware.h"
#include "gun_model.h"

class ButtonController : BaseController {
public:
    ButtonController(ButtonHardware* buttons, GunModel* gun);

    virtual void init() {};

    virtual void run();

    virtual void update() {};

private:
    bool is_pressed(uint8_t bitmap, button_t button);

    //Hardware
    ButtonHardware* m_buttons;

    //Models
    GunModel*       m_gun;
};

#endif //__BUTTON_CONTROLLER_H__
