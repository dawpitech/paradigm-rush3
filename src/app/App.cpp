//
// EPITECH PROJECT, 2025
// App
// File description:
// functions for orchestrator for our GKrellM
//

#include "App.hpp"
#include "displayEngine/IDisplay.hpp"
#include "displayEngine/sfml/SfmlDisplay.hpp"
#include "enums.hpp"
#include "widgetEngine/IModule.hpp"
#include "widgetEngine/WidgetEngine.hpp"
#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>

Krell::App::App()
{
    this->_displayManager = std::make_shared<SfmlDisplay>();
    this->_widgetEngine = std::make_shared<WidgetEngine>();
}

bool Krell::App::run()
{
    auto previousTime = std::time(nullptr);
    auto currentTime = previousTime;

    try {
        while (this->_displayType != Krell::DisplayType::NONE) {
            currentTime = std::time(nullptr);
            this->_displayManager->useEvent();
            if (currentTime < previousTime + 2) {
                continue;
            }
            std::cout << "ici" << std::endl;
            previousTime = currentTime;
            auto modules = this->_widgetEngine->getModules();
            /*auto modules = nullptr;*/
            /*auto sortedModules = this->_sortModules(modules);*/
            this->_displayType = this->_displayManager->displayModules(modules);
        }
    } catch (const Error &error) {
        std::cerr << error.what() << std::endl;
        return false;
    }
    return true;
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
