#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "player_model.h"
using ::testing::_;
using ::testing::Return;

class PlayerModelTest : public ::testing::Test {
protected:
  virtual void SetUp() {
    player_m = new PlayerModel(DEFAULT_HEALTH, DEFAULT_TEAM);
  }

  virtual void TearDown() {
    delete player_m;
    player_m = NULL;
  }

  PlayerModel*  player_m;
  const int DEFAULT_HEALTH = 100;
  const int DEFAULT_TEAM = 1;
};

TEST_F(PlayerModelTest, decreaseHealthReturnsCorrectValue)
{
  EXPECT_TRUE(player_m->decrease_health_by(10));
  EXPECT_TRUE(player_m->decrease_health_by(50));
  EXPECT_FALSE(player_m->decrease_health_by(40));
  EXPECT_FALSE(player_m->decrease_health_by(1));
}

TEST_F(PlayerModelTest, decreaseHealthDoesNotGoNegative)
{
  for (int i = 0; i < 12; i++)
  {
    player_m->decrease_health_by(10);
  }

  EXPECT_EQ(0, player_m->get_current_health());
}

TEST_F(PlayerModelTest, resetHealthUpdatesHealth)
{
  player_m->decrease_health_by(DEFAULT_HEALTH);
  EXPECT_EQ(0, player_m->get_current_health());
  player_m->reset_health();
  EXPECT_EQ(DEFAULT_HEALTH, player_m->get_current_health());
}
