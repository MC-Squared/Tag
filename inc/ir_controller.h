#ifndef __IR_CONTROLLER_H__
#define __IR_CONTROLLER_H__

#include "base_controller.h"
#include "ir_tx_hardware.h"
#include "ir_rx_hardware.h"
#include "gun_model.h"

class IRController {
public:
    IRController(IRTXHardware* ir_tx, IRRXHardware* ir_rx, GunModel* gun);

    virtual void init() {};

    virtual void run();

    virtual void update() {};

private:
    //Hardware
    IRTXHardware* m_ir_tx;
    IRRXHardware* m_ir_rx;

    //Models
    GunModel*       m_gun;
};

#endif //__IR_CONTROLLER_H__
