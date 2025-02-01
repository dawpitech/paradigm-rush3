//
// EPITECH PROJECT, 2025
// App
// File description:
// functions for orchestrator for our GKrellM
//

#include "App.hpp"
#include <iostream>

bool Krell::App::run(const Krell::DisplayType &type)
{
    try {
        this->getModule();
        this->_displayManager->displayModules(*this->_module);
    } catch (const Error &error) {
        std::cerr << error.what() << std::endl;
        return false;
    }
    return true;
}
