#include "player_model.h"

PlayerModel::PlayerModel(uint8_t max_health, uint8_t team)
{
    m_max_health = max_health;
    m_current_health = max_health;
    m_team = team;
};

bool PlayerModel::decrease_health_by(uint8_t decrease)
{
    bool ret = true;
    if (decrease >= m_current_health)
    {
        decrease = m_current_health;
        ret = false;
    }

    m_current_health -= decrease;
    return ret;
}
