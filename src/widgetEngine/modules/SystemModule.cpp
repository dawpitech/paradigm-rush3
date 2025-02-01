/*
** EPITECH PROJECT, 2025
** paradigm-rush3
** File description:
** SystemModule.cpp
*/

#include "SystemModule.hpp"

#include <widgetEngine/widgets/Widget.hpp>

Krell::Modules::SystemModule::SystemModule()
{
    this->addModule(Widgets::Widget(0, "Username"));

}

void Krell::Modules::SystemModule::addModule(const IWidget& widget)
{
    this->_widgets.insert(widget, this->_widgets.begin());
}
