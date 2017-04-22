#ifndef __GUN_MODEL_H__
#define __GUN_MODEL_H__
#include <stdint.h>

enum GunMode {
    MODE_SINGLE = 0,
    MODE_BURST,
    MODE_AUTO
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
    virtual void toggle_mode();

    // Getters
    virtual uint8_t get_current_clip() { return m_current_clip; };

    virtual uint8_t get_bullet_que() { return m_bullet_que; };

    virtual uint16_t get_remaining_ammo() { return m_ammo; };

    virtual GunMode get_mode() { return m_mode; };

private:
    uint8_t     m_clip_size;    //No. of bullets the clip holds when full
    uint8_t     m_current_clip; //No. of bullets in the clip currently
    uint8_t     m_bullet_que;   //No. of bullets that should be fired
    uint16_t    m_ammo;         //No. of bullets remaining (excluding current clip)
    GunMode     m_mode;
};

#endif //__GUN_MODEL_H__
