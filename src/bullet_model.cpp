#include "bullet_model.h"

//MilesTag procotol for bullets:
//8 bits for player id (MSB always 0)
//2 bits for team id
//4 bits for damage

const uint8_t SHIFT_DAMAGE  = 0;
const uint8_t SHIFT_TEAM    = 4;
const uint8_t SHIFT_PLAYER  = 6;

const uint32_t MASK_DAMAGE  = 0x0F << SHIFT_DAMAGE;
const uint32_t MASK_TEAM    = 0x03 << SHIFT_TEAM;
const uint32_t MASK_PLAYER  = 0xFF << SHIFT_PLAYER;

uint8_t BulletModel::get_player_id()
{
  return (uint8_t) ((m_data & MASK_PLAYER) >> SHIFT_PLAYER);
}

uint8_t BulletModel::get_team()
{
  return (uint8_t) ((m_data & MASK_TEAM) >> SHIFT_TEAM);
}

uint8_t BulletModel::get_damage()
{
  return (uint8_t) ((m_data & MASK_DAMAGE) >> SHIFT_DAMAGE);
}
