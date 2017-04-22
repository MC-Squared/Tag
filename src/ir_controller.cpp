#include "ir_controller.h"

IRController::IRController(IRTXHardware* ir_tx, IRRXHardware* ir_rx, GunModel* gun)
{
    m_ir_tx = ir_tx;
    m_ir_rx = ir_rx;
    m_gun = gun;
}

void IRController::run()
{
    while (m_gun->get_bullet_que() > 0 &&
            m_gun->decrement_clip() &&
            m_ir_tx->send(0, 0))
    {}
}
