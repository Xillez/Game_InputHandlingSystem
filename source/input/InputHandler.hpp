#pragma once

#include "InputInterface.hpp"

#include <string>			// string
#include <vector>			// vector
#include <unordered_map>	// unordered_map
#include <utility>			// pair
#include <algorithm>		// find
#include <GLFW/glfw3.h>

/**
 * @brief General InputHandler class. 
 */
class InputHandler
{
public:
	
	/**
	 * @brief InputHandler constructor.
	 */
	InputHandler();
	
	/**
	 * @brief InputHandler constructor.
	 * 
	 * @param window - GLFWwindow* - window to listen to.
	 */
	InputHandler(GLFWwindow* window);

	/**
	 * @brief Function to set the current window listen to.
	 * 
	 * @param window - GLFWwindow* - Window to listen to.
	 */
	void setCurrentWindow(GLFWwindow* window);

	/**
	 * @brief Function for registering keys to check.
	 * 
	 * @param key - int - Key to check for.
	 * 
	 * @return true - If key registered.
	 * @return false - If failed to register.
	 */
	bool registerKey(int key);

	/**
	 * @brief Unregisters the specified key
	 * 
	 * @param key - int - Key to unregister.
	 * 
	 * @return true - If unregistering wa successfull
	 * @return false - If it was unsuccessfull.
	 */
	bool unregisterKey(int key);

	/**
	 * @brief Updates state for next frame.
	 */
	void update();

	/**
	 * @brief Function for getting key state.
	 * 
	 * @param key - int - Wanted key.
	 * 
	 * @return true - Key down.
	 * @return false - Key up.
	 */
	bool getKeyState(int key);

	/**
	 * @brief Function for getting key.
	 * 
	 * @param key - std::string - Wanted key.
	 * 
	 * @return A copy of the wanted key if foun, error key if not.
	 */
	//Key getKey(std::string key);

	/**
	 * @brief Function to check if key is registered.
	 * 
	 * @param key - int - Key to check.
	 * 
	 * @return true - If registered.
	 * @return false - Not registered.
	 */
	bool isRegistered(int key);

	/**
	 * @brief Function to check if key is active.
	 * 
	 * @param key - int - Key to check.
	 * 
	 * @return true - If active.
	 * @return false - Not active.
	 */
	bool isActive(int key);

	/**
	 * @brief Function to activate a key.
	 * 
	 * @param key - int - Key to activate.
	 */
	void activate(int key);

	/**
	 * @brief Function to deactivate a key.
	 * 
	 * @param key - int - Key to deactivate.
	 */
	void deactivate(int key);

	/**
	 * @brief Function to convert Key to printable string.
	 * 
	 * @param key - int - Key to convert.
	 * 
	 * @return std::string - Keys string equivalent.
	 */
	std::string keyToString(int key);

	/**
	 * @brief Function GLFW can call to update keystates.
	 * 
	 * @param window - GLFWwindow* - Window event occured in.
	 * @param key - int - The code for the pressed key.
	 * @param scancode  - int - The scancode for the pressed key.
	 * @param action  - int - The action on the pressedee key. 
	 * @param mods  - int - The modifier pessed with this event.
	 */
	static void onKeyPressed(GLFWwindow* window, int key, int scancode, int action, int mods);

protected:
	std::vector<Key> keys;			//!< Keys registered.

	GLFWwindow* window;				//!< Pointer to window.

	std::unordered_map<int, std::string> keyname = {
		{ Input::KEY_UNKNOWN , std::string("UNKNOWN") }, 
        { Input::KEY_SPACE , std::string("SPACE") }, 
        { Input::KEY_APOSTROPHE , std::string("APOSTROPHE") },  /* ' */
        { Input::KEY_COMMA , std::string("COMMA") },  /*  }, */
        { Input::KEY_MINUS , std::string("MINUS") },  /* - */
        { Input::KEY_PERIOD , std::string("PERIOD") },  /* . */
        { Input::KEY_SLASH , std::string("SLASH") },  /* / */
        { Input::KEY_0 , std::string("0") }, 
        { Input::KEY_1 , std::string("1") }, 
        { Input::KEY_2 , std::string("2") }, 
        { Input::KEY_3 , std::string("3") }, 
        { Input::KEY_4 , std::string("4") }, 
        { Input::KEY_5 , std::string("5") }, 
        { Input::KEY_6 , std::string("6") }, 
        { Input::KEY_7 , std::string("7") }, 
        { Input::KEY_8 , std::string("8") }, 
        { Input::KEY_9 , std::string("9") }, 
        { Input::KEY_SEMICOLON , std::string("SEMICOLON") },  /* ; */
        { Input::KEY_EQUAL , std::string("EQUAL") },  /*"), */
        { Input::KEY_A , std::string("A") }, 
        { Input::KEY_B , std::string("B") }, 
        { Input::KEY_C , std::string("C") }, 
        { Input::KEY_D , std::string("D") }, 
        { Input::KEY_E , std::string("E") }, 
        { Input::KEY_F , std::string("F") }, 
        { Input::KEY_G , std::string("G") }, 
        { Input::KEY_H , std::string("H") }, 
        { Input::KEY_I , std::string("I") }, 
        { Input::KEY_J , std::string("J") }, 
        { Input::KEY_K , std::string("K") }, 
        { Input::KEY_L , std::string("L") }, 
        { Input::KEY_M , std::string("M") }, 
        { Input::KEY_N , std::string("N") }, 
        { Input::KEY_O , std::string("O") }, 
        { Input::KEY_P , std::string("P") }, 
        { Input::KEY_Q , std::string("Q") }, 
        { Input::KEY_R , std::string("R") }, 
        { Input::KEY_S , std::string("S") }, 
        { Input::KEY_T , std::string("T") }, 
        { Input::KEY_U , std::string("U") }, 
        { Input::KEY_V , std::string("V") }, 
        { Input::KEY_W , std::string("W") }, 
        { Input::KEY_X , std::string("X") }, 
        { Input::KEY_Y , std::string("Y") }, 
        { Input::KEY_Z , std::string("Z") }, 
        { Input::KEY_LEFT_BRACKET , std::string("LEFT_BRACKET") }, /* [ */
        { Input::KEY_BACKSLASH , std::string("BACKSLASH") }, /* \ */
        { Input::KEY_RIGHT_BRACKET , std::string("RIGHT_BRACKET") }, /* ] */
        { Input::KEY_GRAVE_ACCENT , std::string("GRAVE_ACCENT") }, /* ` */
        { Input::KEY_WORLD_1 , std::string("WORLD_1") }, /* non-US #1 */
        { Input::KEY_WORLD_2 , std::string("WORLD_2") }, /* non-US #2 */
        { Input::KEY_ESCAPE , std::string("ESCAPE") }, 
        { Input::KEY_ENTER , std::string("ENTER") }, 
        { Input::KEY_TAB , std::string("TAB") }, 
        { Input::KEY_BACKSPACE , std::string("BACKSPACE") }, 
        { Input::KEY_INSERT , std::string("INSERT") }, 
        { Input::KEY_DELETE , std::string("DELETE") }, 
        { Input::KEY_RIGHT , std::string("RIGHT") }, 
        { Input::KEY_LEFT , std::string("LEFT") }, 
        { Input::KEY_DOWN , std::string("DOWN") }, 
        { Input::KEY_UP , std::string("UP") }, 
        { Input::KEY_PAGE_UP , std::string("PAGE_UP") }, 
        { Input::KEY_PAGE_DOWN , std::string("PAGE_DOWN") }, 
        { Input::KEY_HOME , std::string("HOME") }, 
        { Input::KEY_END , std::string("END") }, 
        { Input::KEY_CAPS_LOCK , std::string("CAPS_LOCK") }, 
        { Input::KEY_SCROLL_LOCK , std::string("SCROLL_LOCK") }, 
        { Input::KEY_NUM_LOCK , std::string("NUM_LOCK") }, 
        { Input::KEY_PRINT_SCREEN , std::string("PRINT_SCREEN") }, 
        { Input::KEY_PAUSE , std::string("PAUSE") }, 
        { Input::KEY_ENTER , std::string("ENTER") }, 
        { Input::KEY_F1 , std::string("F1") }, 
        { Input::KEY_F2 , std::string("F2") }, 
        { Input::KEY_F3 , std::string("F3") }, 
        { Input::KEY_F4 , std::string("F4") }, 
        { Input::KEY_F5 , std::string("F5") }, 
        { Input::KEY_F6 , std::string("F6") }, 
        { Input::KEY_F7 , std::string("F7") }, 
        { Input::KEY_F8 , std::string("F8") }, 
        { Input::KEY_F9 , std::string("F9") }, 
        { Input::KEY_F10 , std::string("F10") }, 
        { Input::KEY_F11 , std::string("F11") }, 
        { Input::KEY_F12 , std::string("F12") }, 
        { Input::KEY_F13 , std::string("F13") }, 
        { Input::KEY_F14 , std::string("F14") }, 
        { Input::KEY_F15 , std::string("F15") }, 
        { Input::KEY_F16 , std::string("F16") }, 
        { Input::KEY_F17 , std::string("F17") }, 
        { Input::KEY_F18 , std::string("F18") }, 
        { Input::KEY_F19 , std::string("F19") }, 
        { Input::KEY_F20 , std::string("F20") }, 
        { Input::KEY_F21 , std::string("F21") }, 
        { Input::KEY_F22 , std::string("F22") }, 
        { Input::KEY_F23 , std::string("F23") }, 
        { Input::KEY_F24 , std::string("F24") }, 
        { Input::KEY_F25 , std::string("F25") }, 
        { Input::KEY_KP_0 , std::string("KP_0") }, 
        { Input::KEY_KP_1 , std::string("KP_1") }, 
        { Input::KEY_KP_2 , std::string("KP_2") }, 
        { Input::KEY_KP_3 , std::string("KP_3") }, 
        { Input::KEY_KP_4 , std::string("KP_4") }, 
        { Input::KEY_KP_5 , std::string("KP_5") }, 
        { Input::KEY_KP_6 , std::string("KP_6") }, 
        { Input::KEY_KP_7 , std::string("KP_7") }, 
        { Input::KEY_KP_8 , std::string("KP_8") }, 
        { Input::KEY_KP_9 , std::string("KP_9") }, 
        { Input::KEY_KP_DECIMAL , std::string("KP_DECIMAL") }, 
        { Input::KEY_KP_DIVIDE , std::string("KP_DIVIDE") }, 
        { Input::KEY_KP_MULTIPLY , std::string("KP_MULTIPLY") }, 
        { Input::KEY_KP_SUBTRACT , std::string("KP_SUBTRACT") }, 
        { Input::KEY_KP_ADD , std::string("KP_ADD") }, 
        { Input::KEY_KP_ENTER , std::string("KP_ENTER") }, 
        { Input::KEY_KP_EQUAL , std::string("KP_EQUAL") }, 
        { Input::KEY_LEFT_SHIFT , std::string("LEFT_SHIFT") }, 
        { Input::KEY_LEFT_CONTROL , std::string("LEFT_CONTROL") }, 
        { Input::KEY_LEFT_ALT , std::string("LEFT_ALT") }, 
        { Input::KEY_LEFT_SUPER , std::string("LEFT_SUPER") }, 
        { Input::KEY_RIGHT_SHIFT , std::string("RIGHT_SHIFT") }, 
        { Input::KEY_RIGHT_CONTROL , std::string("RIGHT_CONTROL") }, 
        { Input::KEY_RIGHT_ALT , std::string("RIGHT_ALT") }, 
        { Input::KEY_RIGHT_SUPER , std::string("RIGHT_SUPER") }, 
        { Input::KEY_MENU , std::string("MENU") }, 
        { Input::KEY_LAST , std::string("LAST") }
	};
};