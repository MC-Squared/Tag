#ifndef __PLAYER_MODEL_H__
#define __PLAYER_MODEL_H__
#include <stdint.h>

class PlayerModel {
public:
    PlayerModel(uint8_t max_health, uint8_t team);

    virtual bool decrease_health_by(uint8_t decrease);

    virtual void reset_health() { m_current_health = m_max_health; };

    // Getters
    virtual uint8_t get_max_health() { return m_max_health; }; /*LCOV_EXCL_LINE*/

    virtual uint8_t get_current_health() { return m_current_health; };

    virtual uint8_t get_team() { return m_team; }; /*LCOV_EXCL_LINE*/

private:
    uint8_t     m_max_health;       //Maximum health for this player
    uint8_t     m_current_health;   //Current health of this player
    uint8_t     m_team;             //Current team no.
};

#endif //__PLAYER_MODEL_H__
