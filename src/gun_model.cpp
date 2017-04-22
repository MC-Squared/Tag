#include "gun_model.h"

GunModel::GunModel(uint16_t ammo, uint8_t clip_size)
{
    m_ammo = ammo;
    m_clip_size = clip_size;
    m_current_clip = 0;
    m_bullet_que = 0;
    m_fire_mode = FIRE_MODE_SINGLE;
    m_gun_mode = GUN_MODE_PREGAME;
    this->reload();
};

bool GunModel::decrement_clip()
{
    if (m_current_clip > 0 && m_gun_mode == GUN_MODE_NORMAL)
    {
        m_current_clip--;
        return true;
    }

    return false;
}

bool GunModel::que_bullet()
{
    if (m_gun_mode != GUN_MODE_NORMAL)
        return false;
    
    m_bullet_que++;
    if (m_bullet_que > m_current_clip)
    {
        m_bullet_que = m_current_clip;
        return false;
    }

    return true;
}

void GunModel::reload()
{
    uint16_t take_ammo = m_clip_size;
    if (m_ammo < take_ammo)
        take_ammo = m_ammo;

    m_ammo -= (take_ammo - m_current_clip);
    m_current_clip = take_ammo;
}

void GunModel::toggle_fire_mode()
{
    switch(m_fire_mode)
    {
        case FIRE_MODE_SINGLE:
            m_fire_mode = FIRE_MODE_BURST;
            break;
        case FIRE_MODE_BURST:
            m_fire_mode = FIRE_MODE_AUTO;
            break;
        default:
            m_fire_mode = FIRE_MODE_SINGLE;
            break;
    }
}
