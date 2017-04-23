#ifndef __PLAYER_MODEL_MOCK_H__
#define __PLAYER_MODEL_MOCK_H__

#include "gmock/gmock.h"
#include "player_model.h"

const uint8_t  DEFAULT_HEALTH   = 100;
const uint8_t  DEFAULT_TEAM     = 1;

class PlayerModelMock : public PlayerModel {
 public:
     PlayerModelMock() : PlayerModel(DEFAULT_HEALTH, DEFAULT_TEAM) {};

     MOCK_METHOD1(decrease_health_by, bool(uint8_t));

     MOCK_METHOD0(get_max_health, uint8_t());
     MOCK_METHOD0(get_current_health, uint8_t());
     MOCK_METHOD0(get_team, uint8_t());
};

#endif //__PLAYER_MODEL_MOCK_H__
