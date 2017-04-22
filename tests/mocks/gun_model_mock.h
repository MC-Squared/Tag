#include "gmock/gmock.h"
#include "gun_model.h"

const uint16_t  DEFAULT_AMMO = 100;
const uint8_t   DEFAULT_CLIP = 10;

class GunModelMock : public GunModel {
 public:
     GunModelMock() : GunModel(DEFAULT_AMMO, DEFAULT_CLIP) {};
     MOCK_METHOD0(decrement_clip, bool());
     MOCK_METHOD0(que_bullet, bool());
     MOCK_METHOD0(reload, void());
     MOCK_METHOD0(toggle_fire_mode, void());
};
