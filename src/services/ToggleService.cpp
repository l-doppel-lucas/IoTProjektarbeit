#include "ToggleService.h" 

using namespace ZbW;

ToggleService::ToggleService(QwiicButton *button, LED *led) { 
    m_button = button; 
    m_pressed = false; 
    m_led = led; 
    m_isOn = false; 
    m_led->LEDOff(); 
} 
    
void ToggleService::loop(void) { 
    bool keyWentDown = false; 
    
    if (m_pressed != m_button->isPressed()) { 
        m_pressed = !m_pressed; 
        keyWentDown = m_pressed; 
    } 

    if (keyWentDown) { 
        toggle(); 
    } 
} 

void ToggleService::toggle(void) {
    m_isOn = !m_isOn; 
    
    if (m_isOn) { 
        m_led->setLEDColor(255, 255, 255); 
    } 
    else { 
        m_led->LEDOff(); 
    } 
}