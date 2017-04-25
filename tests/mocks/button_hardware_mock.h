#ifndef __BUTTON_HARDWARE_MOCK_H__
#define __BUTTON_HARDWARE_MOCK_H__

#include "gmock/gmock.h"
#include "button_hardware.h"

class ButtonHardwareMock : public ButtonHardware {
public:
  MOCK_METHOD0(init, void());
  MOCK_METHOD0(get_pressed, uint8_t());
};

#endif //__BUTTON_HARDWARE_MOCK_H__
