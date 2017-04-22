#ifndef __GUN_MODEL_H__
#define __GUN_MODEL_H__
#include <stdint.h>

enum FireMode {
    FIRE_MODE_SINGLE = 0,
    FIRE_MODE_BURST,
    FIRE_MODE_AUTO
};

enum GunMode {
    GUN_MODE_NORMAL = 0,
    GUN_MODE_RELOAD,
    GUN_MODE_SHIELD,
    GUN_MODE_PREGAME,
    GUN_MODE_GAMEOVER
};

class GunModel {
public:
    GunModel(uint16_t ammo, uint8_t clip_size);

    //reduce current clip by 1
    //returns false if current clip is already empty
    virtual bool decrement_clip();

    //Que a bullet to be fired,
    //returns false if que already equals current clip
    //(i.e. no bullets left)
    virtual bool que_bullet();

    //resets current clip, decrements ammo
    virtual void reload();

    //Toggle firing mode
    //Single->burst->auto->single...
    virtual void toggle_fire_mode();

    //Setters
    virtual void set_gun_mode(GunMode mode) { m_gun_mode = mode; }

    // Getters
    virtual uint8_t get_current_clip() { return m_current_clip; };

    virtual uint8_t get_bullet_que() { return m_bullet_que; };

    virtual uint16_t get_remaining_ammo() { return m_ammo; };

    virtual FireMode get_fire_mode() { return m_fire_mode; };

    virtual GunMode get_gun_mode() { return m_gun_mode; };

private:
    uint8_t     m_clip_size;    //No. of bullets the clip holds when full
    uint8_t     m_current_clip; //No. of bullets in the clip currently
    uint8_t     m_bullet_que;   //No. of bullets that should be fired
    uint16_t    m_ammo;         //No. of bullets remaining (excluding current clip)

    FireMode    m_fire_mode;
    GunMode     m_gun_mode;
};

#endif //__GUN_MODEL_H__
