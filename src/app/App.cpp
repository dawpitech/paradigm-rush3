//
// EPITECH PROJECT, 2025
// App
// File description:
// functions for orchestrator for our GKrellM
//

#include <iostream>
#include <memory>
#include <vector>

#include "App.hpp"
#include "enums.hpp"
#include "displayEngine/IDisplay.hpp"
#include "displayEngine/sfml/SfmlDisplay.hpp"
#include "widgetEngine/WidgetEngine.hpp"
#include "widgetEngine/modules/IModule.hpp"

Krell::App::App(const DisplayType &type)
{
    this->_displayType = type;
    if (type == DisplayType::SFML)
        this->_displayManager = std::make_unique<SfmlDisplay>();
    /*if (type == Krell::DisplayType::NCURSES)*/
    /*    this->_displayManager = std::make_shared<NCursesDisplay>();*/
}

[[noreturn]] int Krell::App::run()
{
    auto previousTime = std::time(nullptr);

    if (this->_displayManager == nullptr)
        throw Error("Unable to access display manager");
    try {
        while (this->_displayType != DisplayType::NONE) {
            const std::time_t currentTime = std::time(nullptr);
            this->_displayManager->useEvent();
            if (currentTime < previousTime + 2)
                continue;

            previousTime = currentTime;
            const auto modules = this->_widgetEngine.getModules();
            this->_displayType = this->_displayManager->displayModules(modules);
        }
    } catch (const Error &error) {
        std::cerr << error.what() << std::endl;
        return -1;
    }
    return 0;
}

std::shared_ptr<std::vector<Krell::IModule>> Krell::App::_sortModules(
    std::shared_ptr<std::vector<Krell::IModule>> modules)
{
    /*if (modules == nullptr)*/
    /*     throw Error("Unable to retrieve module for sort");*/
    /*for (size_t i = 0; i < modules->size() - 1; i += 1) {*/
    /*    if ((*modules)[i].getRenderPos() > (*modules)[i + 1].getRenderPos()) {*/
    /*        auto stored = (*modules)[i];*/
    /*        std::swap((*modules)[i], (*modules)[i + 1]);*/
    /*    }*/
    /*}*/
    return nullptr;
}
