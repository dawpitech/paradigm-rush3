//
// EPITECH PROJECT, 2025
// App
// File description:
// functions for orchestrator for our GKrellM
//

#include <iostream>
#include <memory>
#include <thread>

#include "App.hpp"
#include "enums.hpp"
#include "displayEngine/IDisplay.hpp"
#include "displayEngine/ncurses/NCursesDisplay.hpp"
#include "displayEngine/sfml/SFMLDisplay.hpp"
#include "widgetEngine/WidgetEngine.hpp"

Krell::App::App(const DisplayType &type)
{
    this->_displayType = type;
    if (type == DisplayType::NCURSES)
        this->_displayManager = std::make_unique<Displays::NCursesDisplay>();
    else if (type == DisplayType::SFML)
        this->_displayManager = std::make_unique<Displays::SFMLDisplay>();
    else
        throw std::exception();
}

void Krell::App::run()
{
    auto previousTime = std::time(nullptr);

    if (this->_displayManager == nullptr)
        throw std::exception();
    try {
        this->_displayManager->displayModules(this->_widgetEngine.getModules());
        while (true)
        {
            if (std::time(nullptr) < previousTime + 2) {
                // sleep for a short amount to prevent the main thread
                // going brrrr and making the CPU cosplay a toaster
                std::this_thread::sleep_for(std::chrono::milliseconds(10));
                // still handle here the input events to make the UI responsive
                // regardless of the refresh time
                if (this->_displayManager->useEvent())
                {
                    if (this->_displayType == DisplayType::NCURSES)
                    {
                        this->_displayManager = std::make_unique<Displays::SFMLDisplay>();
                        this->_displayType = DisplayType::SFML;
                    }
                    else if (this->_displayType == DisplayType::SFML)
                    {
                        this->_displayManager = std::make_unique<Displays::NCursesDisplay>();
                        this->_displayType = DisplayType::NCURSES;
                    }
                    else
                        throw std::exception();
                    this->_displayManager->displayModules(this->_widgetEngine.getModules());
                }
                continue;
            }
            previousTime = std::time(nullptr);
            this->_widgetEngine.refreshData();
            this->_displayManager->displayModules(this->_widgetEngine.getModules());
        }
    } catch (const std::exception &e)
    {
        if (dynamic_cast<const Displays::SFMLDisplay::UserCalledExitException*>(&e) != nullptr)
            return;
        std::cerr << e.what() << std::endl;
    }
}
