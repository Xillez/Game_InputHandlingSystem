#include "InputHandler.hpp"

InputHandler::InputHandler()
{
    // Reserve for quicker registration.
    this->keys.reserve(25);

    // Save pointer to window.
    this->window = nullptr;
}

InputHandler::InputHandler(GLFWwindow* window)
{
    // Reserve for quicker registration.
    this->keys.reserve(25);

    // Save pointer to window.
    this->window = window;
}

void InputHandler::setCurrentWindow(GLFWwindow* window)
{
    // Save pointer to window.
    this->window = window;
}

bool InputHandler::registerKey(Key key)
{
    // If the key doesn't exists.
    if (!isRegistered(key))
    {
        // Register it and set it as active. 
        this->keys.push_back(key);
        this->keystate[key] = std::pair<bool, bool>(true, false);
        return true;
    }
    // It already exists. 
    return false;
}

bool InputHandler::unregisterKey(Key key)
{
    // If the key doesn't exists.
    if (isRegistered(key))
    {
        // Delete it.
        this->keys.erase(std::find(this->keys.begin(), this->keys.end(), key));
        this->keystate.erase(key);
        return true;
    }
    // Couldn't find it or failed. 
    return false;
}

void InputHandler::update()
{
    //for (auto& item : this->keystate)
    //    ;
}

bool InputHandler::getKeyState(Key key)
{
    if (isRegistered(key))
        return this->keystate[*std::find(this->keys.begin(), this->keys.end(), key)].second;
    return false;
}

bool InputHandler::isRegistered(Key key)
{
    return (std::find(this->keys.begin(), this->keys.end(), key) != this->keys.end());
}

bool InputHandler::isActive(Key key)
{
    if (this->keystate.find(key) != this->keystate.end())
        return this->keystate.find(key)->second.first;
    return false;
}

void InputHandler::activate(Key key)
{
    if (isRegistered(key))
        this->keystate.find(key)->second.second = true;
}

void InputHandler::deactivate(Key key)
{
    if (isRegistered(key))
        this->keystate.find(key)->second.second = false;
}