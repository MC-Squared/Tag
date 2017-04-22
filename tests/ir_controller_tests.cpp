#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "ir_tx_hardware_mock.h"
#include "ir_rx_hardware_mock.h"
#include "gun_model_mock.h"
#include "ir_controller.h"
using ::testing::AtLeast;
using ::testing::_;
using ::testing::Return;

class IRControllerTest : public ::testing::Test {
protected:
    virtual void SetUp() {
        ir_c = new IRController(&ir_tx_h_m, &ir_rx_h_m, &gun_m_m);
        ir_c->init();
    }

    virtual void TearDown() {
        delete ir_c;
        ir_c = NULL;
    }

    IRTXHardwareMock    ir_tx_h_m;
    IRRXHardwareMock    ir_rx_h_m;
    GunModelMock        gun_m_m;
    IRController*       ir_c;
};

TEST_F(IRControllerTest, runSendsQueBullets)
{
    EXPECT_CALL(gun_m_m, get_bullet_que())
        .Times(3)
        .WillOnce(Return(2))
        .WillOnce(Return(1))
        .WillOnce(Return(0));

    EXPECT_CALL(gun_m_m, decrement_clip())
        .Times(2)
        .WillRepeatedly(Return(true));

    EXPECT_CALL(ir_tx_h_m, send(_, _))
        .Times(2)
        .WillRepeatedly(Return(true));

    ir_c->run();
}

TEST_F(IRControllerTest, runBreaksEarlyOnDecrementFail)
{
    EXPECT_CALL(gun_m_m, get_bullet_que())
        .Times(1)
        .WillOnce(Return(2));

    EXPECT_CALL(gun_m_m, decrement_clip())
        .Times(1)
        .WillOnce(Return(false));

    EXPECT_CALL(ir_tx_h_m, send(_, _))
        .Times(0);

    ir_c->run();
}

TEST_F(IRControllerTest, runBreaksEarlyOnIRFail)
{
    EXPECT_CALL(gun_m_m, get_bullet_que())
        .Times(1)
        .WillOnce(Return(2));

    EXPECT_CALL(gun_m_m, decrement_clip())
        .Times(1)
        .WillOnce(Return(true));

    EXPECT_CALL(ir_tx_h_m, send(_, _))
        .Times(1)
        .WillOnce(Return(false));

    ir_c->run();
}
