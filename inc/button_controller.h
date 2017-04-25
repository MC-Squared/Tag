#ifndef __BUTTON_CONTROLLER_H__
#define __BUTTON_CONTROLLER_H__

#include "base_controller.h"
#include "button_hardware.h"
#include "gun_model.h"

class ButtonController : BaseController {
public:
  ButtonController(ButtonHardware* buttons, GunModel* gun);

  virtual void init() {}; /*LCOV_EXCL_LINE*/

  virtual void run();

  virtual void update() {}; /*LCOV_EXCL_LINE*/

private:
  bool is_pressed(uint8_t bitmap, button_t button);

  //Hardware
  ButtonHardware* m_buttons;

  //Models
  GunModel*       m_gun;
};

#endif //__BUTTON_CONTROLLER_H__
