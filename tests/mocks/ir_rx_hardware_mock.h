#ifndef __IR_RX_HARDWARE_MOCK_H__
#define __IR_RX_HARDWARE_MOCK_H__

#include "gmock/gmock.h"
#include "ir_rx_hardware.h"

class IRRXHardwareMock : public IRRXHardware {
public:
  MOCK_METHOD0(init, void());
  MOCK_METHOD0(has_bullet, bool());
  MOCK_METHOD0(get_bullet, uint32_t());
};

#endif //__IR_RX_HARDWARE_MOCK_H__
