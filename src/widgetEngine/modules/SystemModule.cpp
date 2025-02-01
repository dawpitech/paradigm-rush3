/*
** EPITECH PROJECT, 2025
** paradigm-rush3
** File description:
** SystemModule.cpp
*/

#include "SystemModule.hpp"

#include <widgetEngine/widgets/StringWidget.hpp>

Krell::Modules::SystemModule::SystemModule()
{
    std::string username(256, '\0');
    getlogin_r(username.data(), 256);
    std::string hostname(256, '\0');
    gethostname(hostname.data(), 256);
    std::string opSys = "UWUBUNTU";
    std::string kernel = "6.x.x gnu/linux";

    this->addModule(Widgets::StringWidget(std::string(username), "Username:"));
    this->addModule(Widgets::StringWidget(hostname, "Hostname:"));
    this->addModule(Widgets::StringWidget(opSys, "Op. sys.:"));
    this->addModule(Widgets::StringWidget(kernel, "Kernel:"));
}

void Krell::Modules::SystemModule::addModule(const IWidget& widget)
{
    auto modules = *this->_widgets;
    modules.insert(modules.begin(), widget);
}
