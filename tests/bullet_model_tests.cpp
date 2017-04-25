#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "bullet_model.h"
using ::testing::_;
using ::testing::Return;

const uint8_t EXPECT_PLAYER_1 = 123;
const uint8_t EXPECT_TEAM_1 = 2;
const uint8_t EXPECT_DAMAGE_1 = 2;

const uint32_t TEST_BULLET_1 = ((EXPECT_PLAYER_1 << 6) |
  (EXPECT_TEAM_1 << 4) | (EXPECT_DAMAGE_1));

class BulletModelTest : public ::testing::Test {
protected:
  virtual void SetUp() {
    bullet_m = new BulletModel();
    bullet_m->set_data(TEST_BULLET_1);
  }

  virtual void TearDown() {
    delete bullet_m;
    bullet_m = NULL;
  }

  BulletModel*  bullet_m;
};

TEST_F(BulletModelTest, getPlayerIDReturnsCorrect)
{
  EXPECT_EQ(EXPECT_PLAYER_1, bullet_m->get_player_id());
}

TEST_F(BulletModelTest, getTeamReturnsCorrect)
{
  EXPECT_EQ(EXPECT_TEAM_1, bullet_m->get_team());
}

TEST_F(BulletModelTest, getDamageReturnsCorrect)
{
  EXPECT_EQ(EXPECT_DAMAGE_1, bullet_m->get_damage());
}
