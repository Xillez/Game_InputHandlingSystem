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
	 * @brief Set the current window listen to.
	 * 
	 * @param window - GLFWwindow* - Window to listen to.
	 */
	void setCurrentWindow(GLFWwindow* window);

	/**
	 * @brief A function for registering keys to check.
	 * 
	 * @param key - Key (enum) - Key to check for.
	 * 
	 * @return true - If key registered.
	 * @return false - If failed to register.
	 */
	bool registerKey(Key key);

	/**
	 * @brief Unregisters the specified key
	 * 
	 * @param key - Key (enum) - Key to unregister.
	 * 
	 * @return true - If unregistering wa successfull
	 * @return false - If it was unsuccessfull.
	 */
	bool unregisterKey(Key key);

	/**
	 * @brief Updates state for next frame.
	 */
	void update();

	/**
	 * @brief A function for getting key state.
	 * 
	 * @param key - Key (enum) - Wanted key.
	 * 
	 * @return true - Key down.
	 * @return false - Key up.
	 */
	bool getKeyState(Key key);

	/**
	 * @brief A function for getting key.
	 * 
	 * @param key - Key (enum) - Wanted key.
	 * 
	 * @return A copy of the wanted key if found, error key if not.
	 */
	//Key getKey(std::string key);

	/**
	 * @brief A function to check if key is registered.
	 * 
	 * @param key - Key (enum) - Key to check.
	 * 
	 * @return true - If registered.
	 * @return false - Not registered.
	 */
	bool isRegistered(Key key);

	/**
	 * @brief A function to check if key is active.
	 * 
	 * @param key - Key (enum) - Key to check.
	 * 
	 * @return true - If active.
	 * @return false - Not active.
	 */
	bool isActive(Key key);

	/**
	 * @brief A function to activate a key.
	 * 
	 * @param key - Key (enum) - Key to activate.
	 */
	void activate(Key key);

	/**
	 * @brief A function to deactivate a key.
	 * 
	 * @param key - Key (enum) - Key to deactivate.
	 */
	void deactivate(Key key);

	/**
	 * @brief Function to convert Key to printable string.
	 * 
	 * @param key - Key (enum) - Key to convert.
	 * 
	 * @return std::string - Keys string equivalent.
	 */
	//std::string keyToString(Key key);

	static void onKeyPressed(GLFWwindow* window, int key, int scancode, int action, int mods);

protected:
	std::vector<Key> keys;										//!< Keys registered.
	std::unordered_map<Key, std::pair<bool, bool>> keystate;	//!< The state of the registered key.

	GLFWwindow* window;
};