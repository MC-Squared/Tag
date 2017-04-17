#include "gmock/gmock.h"
#include "button_hardware.h"

class ButtonHardwareMock : public ButtonHardware {
 public:
     //ButtonHardwareMock() {};
     MOCK_METHOD0(init, void());
     MOCK_METHOD0(get_pressed, uint8_t());
};
