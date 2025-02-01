//
// EPITECH PROJECT, 2025
// App
// File description:
// functions for orchestrator for our GKrellM
//

#include <iostream>
#include <memory>
#include <thread>
#include <vector>

#include "App.hpp"

#include "enums.hpp"
#include "displayEngine/IDisplay.hpp"
#include "displayEngine/ncurses/NCursesDisplay.hpp"
#include "widgetEngine/WidgetEngine.hpp"
#include "widgetEngine/modules/IModule.hpp"

Krell::App::App(const DisplayType &type)
{
    this->_displayType = type;
    if (type == DisplayType::NCURSES)
        this->_displayManager = std::make_unique<Displays::NCursesDisplay>();
}

[[noreturn]] int Krell::App::run()
{
    auto previousTime = std::time(nullptr);

    if (this->_displayManager == nullptr)
        throw Error("Unable to access display manager");
    try {
        while (this->_displayType != DisplayType::NONE)
        {
            if (std::time(nullptr) < previousTime + 2) {
                // sleep for a short amount to prevent the main thread
                // going brrrr and making the CPU cosplay a toaster
                std::this_thread::sleep_for(std::chrono::milliseconds(10));
                // still handle here the input events to make the UI responsive
                // regardless of the refresh time
                this->_displayManager->useEvent();
                continue;
            }
            previousTime = std::time(nullptr);
            this->_widgetEngine.refreshData();
            this->_displayManager->displayModules(this->_widgetEngine.getModules());
        }
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
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
