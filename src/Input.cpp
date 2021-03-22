#include "Input.h"

Input* Input::instance = NULL;

Input* Input::getInstance() {
	if (instance == NULL) {
		instance = new Input();
	}
	return instance;
}

Input::Input() {
	if (instance != NULL) { return; }
	mWindow = NULL;
}

Input::~Input() {

}

void Input::updateEvents() {
	if (mWindow == NULL) { return; }
	for (int i = 0; i < KeyboardKeys::LAST_NO_USE; i++) {
		key_pressed[i] = false;
		key_released[i] = false;
	}

	sf::Event event;
	while (mWindow->pollEvent(event)) {
		switch (event.type) {
			default: break;
		case sf::Event::Closed:
			mWindow->close();
			break;
		case sf::Event::KeyPressed:
			keyPressedEvent(event.key.code);
			break;
		case sf::Event::KeyReleased:
			keyPressedEvent(event.key.code);
			break;
		case sf::Event::MouseButtonPressed:
			break;
		}
	}
}

void Input::setWindow(sf::RenderWindow* window) {
	mWindow = window;
}


Input::KeyboardKeys Input::getKeyCode(sf::Keyboard::Key key) {
	KeyboardKeys ret_key = LAST_NO_USE;
	switch (key) {
	default: break;
	case sf::Keyboard::Q:			ret_key = KEY_Q; break;
	case sf::Keyboard::W:			ret_key = KEY_W; break;
	case sf::Keyboard::E:			ret_key = KEY_E; break;
	case sf::Keyboard::R:			ret_key = KEY_R; break;
	case sf::Keyboard::T:			ret_key = KEY_T; break;
	case sf::Keyboard::Y:			ret_key = KEY_Y; break;
	case sf::Keyboard::U:			ret_key = KEY_U; break;
	case sf::Keyboard::I:			ret_key = KEY_I; break;
	case sf::Keyboard::O:			ret_key = KEY_O; break;
	case sf::Keyboard::P:			ret_key = KEY_P; break;
	case sf::Keyboard::A:			ret_key = KEY_A; break;
	case sf::Keyboard::S:			ret_key = KEY_S; break;
	case sf::Keyboard::D:			ret_key = KEY_D; break;
	case sf::Keyboard::F:			ret_key = KEY_F; break;
	case sf::Keyboard::G:			ret_key = KEY_G; break;
	case sf::Keyboard::H:			ret_key = KEY_H; break;
	case sf::Keyboard::J:			ret_key = KEY_J; break;
	case sf::Keyboard::K:			ret_key = KEY_K; break;
	case sf::Keyboard::L:			ret_key = KEY_L; break;
	case sf::Keyboard::Z:			ret_key = KEY_Z; break;
	case sf::Keyboard::X:			ret_key = KEY_X; break;
	case sf::Keyboard::C:			ret_key = KEY_C; break;
	case sf::Keyboard::V:			ret_key = KEY_V; break;
	case sf::Keyboard::B:			ret_key = KEY_B; break;
	case sf::Keyboard::N:			ret_key = KEY_N; break;
	case sf::Keyboard::M:			ret_key = KEY_M; break;
	case sf::Keyboard::Num0:		ret_key = KEY_0; break;
	case sf::Keyboard::Num1:		ret_key = KEY_1; break;
	case sf::Keyboard::Num2:		ret_key = KEY_2; break;
	case sf::Keyboard::Num3:		ret_key = KEY_3; break;
	case sf::Keyboard::Num4:		ret_key = KEY_4; break;
	case sf::Keyboard::Num5:		ret_key = KEY_5; break;
	case sf::Keyboard::Num6:		ret_key = KEY_6; break;
	case sf::Keyboard::Num7:		ret_key = KEY_7; break;
	case sf::Keyboard::Num8:		ret_key = KEY_8; break;
	case sf::Keyboard::Num9:		ret_key = KEY_9; break;
	case sf::Keyboard::Numpad0:		ret_key = NUMPAD0; break;
	case sf::Keyboard::Numpad1:		ret_key = NUMPAD1; break;
	case sf::Keyboard::Numpad2:		ret_key = NUMPAD2; break;
	case sf::Keyboard::Numpad3:		ret_key = NUMPAD3; break;
	case sf::Keyboard::Numpad4:		ret_key = NUMPAD4; break;
	case sf::Keyboard::Numpad5:		ret_key = NUMPAD5; break;
	case sf::Keyboard::Numpad6:		ret_key = NUMPAD6; break;
	case sf::Keyboard::Numpad7:		ret_key = NUMPAD7; break;
	case sf::Keyboard::Numpad8:		ret_key = NUMPAD8; break;
	case sf::Keyboard::Numpad9:		ret_key = NUMPAD9; break;
	case sf::Keyboard::Space:		ret_key = SPACE; break;
	case sf::Keyboard::BackSpace:	ret_key = BACKSPACE; break;
	case sf::Keyboard::Enter:		ret_key = ENTER; break;
	case sf::Keyboard::LShift:
	case sf::Keyboard::RShift:		ret_key = SHIFT; break;
	case sf::Keyboard::RControl:
	case sf::Keyboard::LControl:	ret_key = CONTROL; break;
	case sf::Keyboard::LAlt:
	case sf::Keyboard::RAlt:
		ret_key = ALT; break;
	case sf::Keyboard::Tab:			ret_key = TAB; break;
	case sf::Keyboard::Escape:		ret_key = ESCAPE; break;
	case sf::Keyboard::Down:		ret_key = ARROW_DOWN; break;
	case sf::Keyboard::Up:			ret_key = ARROW_UP; break;
	case sf::Keyboard::Right:		ret_key = ARROW_RIGHT; break;
	case sf::Keyboard::Left:		ret_key = ARROW_LEFT; break;
	}
	return ret_key;
}

void Input::keyPressedEvent(sf::Keyboard::Key key){
	Input::KeyboardKeys pressed_key = getKeyCode(key);
	if (pressed_key != LAST_NO_USE) {
		if(!key_down[pressed_key]){
			key_pressed[pressed_key] = true;
		}
		key_down[pressed_key] = true;
		key_released[pressed_key] = false;
	}
}

void Input::keyReleasedEvent(sf::Keyboard::Key key) {
	Input::KeyboardKeys released_key = getKeyCode(key);
	if (released_key != LAST_NO_USE) {
		key_pressed[released_key] = true;
		key_down[released_key] = true;
		key_released[released_key] = true;
	}
}

bool Input::isKeyPressed(KeyboardKeys key) {
	if (key < 0 || key >= LAST_NO_USE) {
		return false;
	}
	return key_pressed[key];
}
bool Input::isKeyDown(KeyboardKeys key) {
	if (key < 0 || key >= LAST_NO_USE) {
		return false;
	}
	return key_down[key];
}
bool Input::isKeyReleased(KeyboardKeys key) {
	if (key < 0 || key >= LAST_NO_USE) {
		return false;
	}
	return key_released[key];
}

