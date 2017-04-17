#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "button_hardware_mock.h"
#include "gun_model_mock.h"
#include "button_controller.h"
using ::testing::AtLeast;
using ::testing::_;
using ::testing::Return;

class ButtonControllerTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
    button_c = new ButtonController(&button_h_m, &gun_m_m);
  }

  virtual void TearDown() {
      delete button_c;
      button_c = NULL;
  }

  ButtonHardwareMock    button_h_m;
  GunModelMock          gun_m_m;
  ButtonController*     button_c;
};

TEST_F(ButtonControllerTest, runDoesNothingWhenNoPress)
{
    EXPECT_CALL(button_h_m, get_pressed())
        .Times(1)
        .WillOnce(Return(0));

    EXPECT_CALL(gun_m_m, decrement_clip())
        .Times(0);

    button_c->run();
}

TEST_F(ButtonControllerTest, runDecrementsClipAmmoOnTrigger)
{
    EXPECT_CALL(button_h_m, get_pressed())
        .Times(1)
        .WillOnce(Return(BUTTON_TRIGGER));

    EXPECT_CALL(gun_m_m, decrement_clip())
        .Times(1)
        .WillOnce(Return(true));

    button_c->run();
}

TEST_F(ButtonControllerTest, runCallsReloadOnReload)
{
    EXPECT_CALL(button_h_m, get_pressed())
        .Times(1)
        .WillOnce(Return(BUTTON_RELOAD));

    EXPECT_CALL(gun_m_m, reload())
        .Times(1);

    button_c->run();
}

TEST_F(ButtonControllerTest, runChangesModeOnMode)
{
    EXPECT_CALL(button_h_m, get_pressed())
        .Times(1)
        .WillOnce(Return(BUTTON_MODE));

    EXPECT_CALL(gun_m_m, toggle_mode())
        .Times(1);

    button_c->run();
}
