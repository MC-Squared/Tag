#ifndef __IR_TX_HARDWARE_MOCK_H__
#define __IR_TX_HARDWARE_MOCK_H__

#include "gmock/gmock.h"
#include "ir_tx_hardware.h"

class IRTXHardwareMock : public IRTXHardware {
 public:
     MOCK_METHOD0(init, void());
     MOCK_METHOD2(send, bool(uint32_t bullet, uint8_t bullet_len));
};

#endif //__IR_TX_HARDWARE_MOCK_H__
