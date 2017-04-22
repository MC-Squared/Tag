#include "ir_controller.h"

IRController::IRController(IRTXHardware* ir_tx, IRRXHardware* ir_rx, GunModel* gun)
{
    m_ir_tx = ir_tx;
    m_ir_rx = ir_rx;
    m_gun = gun;
}

void IRController::run()
{
    GunMode mode = m_gun->get_gun_mode();

    if (m_ir_rx->has_bullet() &&
        (mode == GUN_MODE_NORMAL ||
        mode == GUN_MODE_RELOAD))
    {
        m_ir_rx->get_bullet();
        m_gun->set_gun_mode(GUN_MODE_SHIELD);
        return;
    }

    //Cannot shoot unless in normal mode
    if(mode != GUN_MODE_NORMAL)
        return;

    while (m_gun->get_bullet_que() > 0 &&
            m_gun->decrement_clip() &&
            m_ir_tx->send(0, 0))
    {}
}
