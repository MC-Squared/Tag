#ifndef __IR_RX_HARDWARE_MOCK_H__
#define __IR_RX_HARDWARE_MOCK_H__

#include "gmock/gmock.h"
#include "ir_rx_hardware.h"

class IRRXHardwareMock : public IRRXHardware {
 public:
     MOCK_METHOD0(init, void());
     MOCK_METHOD1(receive, bool(uint32_t* received));
};

#endif //__IR_RX_HARDWARE_MOCK_H__
