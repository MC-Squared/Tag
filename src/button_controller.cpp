#include "button_controller.h"

ButtonController::ButtonController(ButtonHardware* buttons, GunModel* gun)
{
    m_buttons = buttons;
    m_gun = gun;
}

void ButtonController::init()
{
}

void ButtonController::run()
{
    uint8_t pressed = m_buttons->get_pressed();

    if (this->is_pressed(pressed, BUTTON_TRIGGER))
    {
        m_gun->decrement_clip();
    }

    if (this->is_pressed(pressed, BUTTON_RELOAD))
    {
        m_gun->reload();
    }

    if (this->is_pressed(pressed, BUTTON_MODE))
    {
        m_gun->toggle_mode();
    }
}

void ButtonController::interrupt()
{

}

bool ButtonController::is_pressed(uint8_t bitmap, button_t button)
{
    return (bitmap & button) > 0;
}
