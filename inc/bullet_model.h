#ifndef __BULLET_MODEL_H__
#define __BULLET_MODEL_H__
#include <stdint.h>

class BulletModel {
public:
  BulletModel() {};

  void set_data(uint32_t raw_data) { m_data = raw_data; };

  uint8_t get_player_id();

  uint8_t get_team();

  uint8_t get_damage();

private:
  uint32_t  m_data;
};

#endif //__BULLET_MODEL_H__
