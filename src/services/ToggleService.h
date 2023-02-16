#pragma once 
#include <Sparkfun_Qwiic_Button.h> 
#include <QwiicLedStick.h> 

namespace ZbW { 

    class ToggleService { 

        public: ToggleService(QwiicButton *button, LED *led); 
        void loop(void); 

        protected: void toggle(void);

        private: QwiicButton *m_button;

        bool m_pressed; 
        LED * m_led; 
        bool m_isOn;

    }; 
};