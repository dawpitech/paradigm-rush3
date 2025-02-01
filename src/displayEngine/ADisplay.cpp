//
// EPITECH PROJECT, 2025
// ADisplay
// File description:
// functions to display sfml
//

#include "ADisplay.hpp"
#include "widgetEngine/modules/IModule.hpp"
#include "enums.hpp"
#include "widgetEngine/widgets/AWidget.hpp"
#include "widgetEngine/widgets/StringWidget.hpp"
#include <memory>

Krell::DisplayType Krell::ADisplay::displayModules(
            const std::shared_ptr<std::vector<std::shared_ptr<IModule>>> modules) const
{
    if (modules == nullptr) {
        throw Error("Modules not found in displayModules");
    }
    for (auto &module : *modules) {
        this->_displayWidgets(*module);
    }
    return Krell::DisplayType::SFML;
}

void Krell::ADisplay::_displayWidgets(const IModule &module) const
{
    this->_displayBaseModule(module);
    for (auto widget : module.getWidgets()) {

        /*if (dynamic_cast<Krell::Widgets::HistogramWidget *>(widget.get()) != nullptr) {*/
        /*    this->_displayHistogramWidget(*widget);*/
        /*    return;*/
        /*}*/
        /*if (dynamic_cast<Krell::Widgets::ProgressBarWidget *>(widget.get()) != nullptr) {*/
        /*    this->_displayProgressBarWidget(*widget);*/
        /*    return;*/
        /*}*/
        /*if (dynamic_cast<Krell::Widgets::ClockWidget *>(widget.get()) != nullptr) {*/
        /*    this->_displayClockWidget(*widget);*/
        /*    return;*/
        /*}*/
        /*if (dynamic_cast<Krell::Widgets::RangedWidget *>(widget.get()) != nullptr) {*/
        /*    this->_displayRangedWidget(*widget);*/
        /*    return;*/
        /*}*/
        /*if (dynamic_cast<Krell::Widgets::NumericWidget *>(widget.get()) != nullptr) {*/
        /*    this->_displayNumericWidget(*widget);*/
        /*    return;*/
        /*}*/
        if (dynamic_cast<Krell::Widgets::StringWidget *>(widget.get()) != nullptr) {
            std::cout << "Je suis un string widget" << std::endl;
            this->_displayStringWidget(*widget);
            return;
        }
        throw Error("Unknown module");
    }
}
