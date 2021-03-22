#ifndef INPUT_H
#define INPUT_H

#include "includes.h"
#include <SFML/Graphics.hpp>

class Input {
    public:
        enum KeyboardKeys {
            KEY_Q, KEY_W, KEY_E, KEY_R, KEY_T, KEY_Y, KEY_U, KEY_I, KEY_O, KEY_P,
            KEY_A, KEY_S, KEY_D, KEY_F, KEY_G, KEY_H, KEY_J, KEY_K, KEY_L,
            KEY_Z, KEY_X, KEY_C, KEY_V, KEY_B, KEY_N, KEY_M,
            KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_0,
            NUMPAD1, NUMPAD2, NUMPAD3, NUMPAD4, NUMPAD5,
            NUMPAD6, NUMPAD7, NUMPAD8, NUMPAD9, NUMPAD0,
            SPACE, ENTER, BACKSPACE, SHIFT, TAB, CONTROL, ALT, ESCAPE,
            ARROW_UP, ARROW_DOWN, ARROW_LEFT, ARROW_RIGHT,
            LAST_NO_USE
        };
    
        Input();
        ~Input();
    
        void updateEvents();
        void setWindow(sf::RenderWindow* window);

        bool isKeyPressed(KeyboardKeys key);
        bool isKeyDown(KeyboardKeys key);
        bool isKeyReleased(KeyboardKeys key);
        static Input* getInstance();
    private:
        Input::KeyboardKeys getKeyCode(sf::Keyboard::Key key);
        void keyPressedEvent(sf::Keyboard::Key key);
        void keyReleasedEvent(sf::Keyboard::Key key);
        static Input* instance;
        sf::RenderWindow* mWindow;
        bool key_pressed[LAST_NO_USE];
        bool key_down[LAST_NO_USE];
        bool key_released[LAST_NO_USE];
};

#endif