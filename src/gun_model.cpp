#include "gun_model.h"

GunModel::GunModel(uint16_t ammo, uint8_t clip_size)
{
    m_ammo = ammo;
    m_clip_size = clip_size;
    m_current_clip = 0;
    m_mode = MODE_SINGLE;
    this->reload();
};

bool GunModel::decrement_clip()
{
    if (m_current_clip > 0)
    {
        m_current_clip--;
        return true;
    }

    return false;
}

void GunModel::reload()
{
    uint16_t take_ammo = m_clip_size;
    if (m_ammo < take_ammo)
        take_ammo = m_ammo;

    m_ammo -= (take_ammo - m_current_clip);
    m_current_clip = take_ammo;
}

void GunModel::toggle_mode()
{
    switch(m_mode)
    {
        case MODE_SINGLE:
            m_mode = MODE_BURST;
            break;
        case MODE_BURST:
            m_mode = MODE_AUTO;
            break;
        default:
            m_mode = MODE_SINGLE;
            break;
    }
}
