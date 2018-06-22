#pragma once

#include "InputInterface.hpp"

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cstdlib>
#include <utility>
#include <tuple>
#include <string>

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
	 * @brief A function for registering keys to check.
	 * 
	 * @param key - Key (enum) - key to check for.
	 */
	bool registerKey(Key key);

	/**
	 * @brief Updates state for next frame.
	 */
	void update();

	/**
	 * @brief A function for getting key state.
	 * 
	 * @param key - Key (enum) - wanted key.
	 */
	bool getKeyState(Key key);

	/**
	 * @brief Function to convert key to printable string.
	 * 
	 * @param key - Key (enum) - key to convert.
	 * @return std::string - Keys string equivalent.
	 */
	//std::string keyToString(Key key);

private:
	std::unordered_map<Key, bool> keystate;								//!< Posistion of entity.
};