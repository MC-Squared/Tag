#ifndef __IR_RX_HARDWARE_H__
#define __IR_RX_HARDWARE_H__
#include <stdint.h>

class IRRXHardware {
public:
  IRRXHardware() {};

  virtual void init() {};

  virtual bool has_bullet() {};

  virtual uint32_t get_bullet() {};
};

#endif //__IR_RX_HARDWARE_H__
