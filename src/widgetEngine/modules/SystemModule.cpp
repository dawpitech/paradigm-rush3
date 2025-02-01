/*
** EPITECH PROJECT, 2025
** paradigm-rush3
** File description:
** SystemModule.cpp
*/

#include "SystemModule.hpp"
#include "AModule.hpp"
#include "widgetEngine/widgets/StringWidget.hpp"

Krell::Modules::SystemModule::SystemModule()
{
    this->_render_name = std::string("System Infos");

    std::string username(256, '\0');
    getlogin_r(username.data(), 256);
    std::string hostname(256, '\0');
    gethostname(hostname.data(), 256);
    std::string opSys = "UWUBUNTU";
    std::string kernel = "6.x.x gnu/linux";

    this->_widgets.push_back(std::make_unique<Widgets::StringWidget>
        ("Username:", username));
    this->_widgets.push_back(std::make_unique<Widgets::StringWidget>
        ("Hostname:", hostname));
    this->_widgets.push_back(std::make_unique<Widgets::StringWidget>
        ("Op. sys.:", opSys));
    this->_widgets.push_back(std::make_unique<Widgets::StringWidget>
        ("Kernel:", kernel));
}

void Krell::Modules::SystemModule::update() const
{

}
