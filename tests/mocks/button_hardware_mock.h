#include "gmock/gmock.h"
#include "button_hardware.h"

class ButtonHardwareMock : public ButtonHardware {
 public:
     ButtonHardwareMock() {};
  MOCK_METHOD1(init, void(uint8_t gpio));
  MOCK_METHOD0(is_pressed, bool());
};
