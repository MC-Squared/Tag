#ifndef __IR_CONTROLLER_H__
#define __IR_CONTROLLER_H__

#include "base_controller.h"
#include "ir_tx_hardware.h"
#include "ir_rx_hardware.h"
#include "gun_model.h"
#include "player_model.h"

class IRController {
public:
  IRController(
    IRTXHardware* ir_tx,
    IRRXHardware* ir_rx,
    GunModel* gun,
    PlayerModel* player);

  virtual void init() {}; /*LCOV_EXCL_LINE*/

  virtual void run();

  virtual void update() {}; /*LCOV_EXCL_LINE*/

private:
  //Hardware
  IRTXHardware* m_ir_tx;
  IRRXHardware* m_ir_rx;

  //Models
  GunModel*     m_gun;
  PlayerModel*  m_player;
};

#endif //__IR_CONTROLLER_H__
