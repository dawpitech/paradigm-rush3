/*
** EPITECH PROJECT, 2025
** paradigm-rush3
** File description:
** WidgetEngine.cpp
*/

#include "WidgetEngine.hpp"
#include "modules/SystemModule.hpp"

WidgetEngine::WidgetEngine()
{
    this->_modules = std::make_shared<std::vector<std::shared_ptr<Krell::IModule>>>();
    this->_modules->push_back(std::make_shared<Krell::Modules::SystemModule>());
}

void WidgetEngine::refreshData() const
{
    //for (const auto module : *this->_modules)
    //    module->update();
}
