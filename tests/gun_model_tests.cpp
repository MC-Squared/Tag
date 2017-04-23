#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "gun_model.h"
using ::testing::AtLeast;
using ::testing::_;
using ::testing::Return;

//

class GunModelTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
      gun_m = new GunModel(100, 5);
  }

  virtual void TearDown() {
      delete gun_m;
      gun_m = NULL;
  }

  GunModel*  gun_m;
};

TEST_F(GunModelTest, decrementClipReturnsCorrectValue)
{
    EXPECT_EQ(5, gun_m->get_current_clip());
    EXPECT_TRUE(gun_m->decrement_clip());
    EXPECT_TRUE(gun_m->decrement_clip());
    EXPECT_TRUE(gun_m->decrement_clip());
    EXPECT_TRUE(gun_m->decrement_clip());
    EXPECT_TRUE(gun_m->decrement_clip());
    EXPECT_FALSE(gun_m->decrement_clip());
}

TEST_F(GunModelTest, decrementClipDoesNotGoNegative)
{
    EXPECT_EQ(5, gun_m->get_current_clip());
    EXPECT_TRUE(gun_m->decrement_clip());
    for(int i = 0; i < 10; i++)
    {
        gun_m->decrement_clip();
    }
    EXPECT_EQ(0, gun_m->get_current_clip());
    EXPECT_FALSE(gun_m->decrement_clip());
    EXPECT_EQ(0, gun_m->get_current_clip());
}

TEST_F(GunModelTest, reloadUpdatesEmptyClip)
{
    //Starting: clip: 5, ammo: 95
    //empty the clip
    for(int i = 0; i < 10; i++)
    {
        gun_m->decrement_clip();
    }

    EXPECT_EQ(0, gun_m->get_current_clip());
    EXPECT_EQ(95, gun_m->get_remaining_ammo());

    gun_m->reload();

    EXPECT_EQ(5, gun_m->get_current_clip());
    EXPECT_EQ(90, gun_m->get_remaining_ammo());
}

TEST_F(GunModelTest, reloadUpdatesPartialClip)
{
    //Starting: clip: 5, ammo: 95
    for(int i = 0; i < 2; i++)
    {
        gun_m->decrement_clip();
    }

    //Now: clip: 3, ammo: 95
    EXPECT_EQ(3, gun_m->get_current_clip());
    EXPECT_EQ(95, gun_m->get_remaining_ammo());

    gun_m->reload();

    EXPECT_EQ(5, gun_m->get_current_clip());
    EXPECT_EQ(93, gun_m->get_remaining_ammo());
}

TEST_F(GunModelTest, reloadUpdatesWithLowAmmo)
{
    GunModel gm(8, 5);
    EXPECT_EQ(5, gm.get_current_clip());
    for(int i = 0; i < 5; i++)
    {
        gm.decrement_clip();
    }
    gm.reload();

    EXPECT_EQ(3, gm.get_current_clip());
    EXPECT_EQ(0, gm.get_remaining_ammo());
}

TEST_F(GunModelTest, toggleModeCorrectlyToggles)
{
    EXPECT_EQ(MODE_SINGLE, gun_m->get_mode());
    gun_m->toggle_mode();
    EXPECT_EQ(MODE_BURST, gun_m->get_mode());
    gun_m->toggle_mode();
    EXPECT_EQ(MODE_AUTO, gun_m->get_mode());
    gun_m->toggle_mode();
    EXPECT_EQ(MODE_SINGLE, gun_m->get_mode());
}

TEST_F(GunModelTest, queBulletDoesNotExceedClipSize)
{
    EXPECT_EQ(0, gun_m->get_bullet_que());
    EXPECT_TRUE(gun_m->que_bullet());
    EXPECT_EQ(1, gun_m->get_bullet_que());
    for(int i = 0; i < 7; i++)
    {
        gun_m->que_bullet();
    }
    EXPECT_EQ(5, gun_m->get_bullet_que());
    EXPECT_FALSE(gun_m->que_bullet());
}
