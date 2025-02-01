//
// EPITECH PROJECT, 2025
// ADisplay
// File description:
// functions to display sfml
//

#include "ADisplay.hpp"
#include "widgetEngine/IModule.hpp"
#include "enums.hpp"
#include "widgetEngine/IWidget.hpp"
#include "widgetEngine/widgets/StringWidget.hpp"
#include <memory>

Krell::DisplayType Krell::ADisplay::displayModules(
            const std::shared_ptr<std::vector<std::unique_ptr<IModule>>> modules) const
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
    /*for (auto widget : module.getWidgets()) {*/
    /*    if (dynamic_cast<Krell::Widgets::HistogramWidget *>(widget.get()) != nullptr) {*/
    /*        this->_displayHistogramWidget(*widget);*/
    /*        return;*/
    /*    }*/
    /*    if (dynamic_cast<Krell::Widgets::ProgressBarWidget *>(widget.get()) != nullptr) {*/
    /*        this->_displayProgressBarWidget(*widget);*/
    /*        return;*/
    /*    }*/
    /*    if (dynamic_cast<Krell::Widgets::ClockWidget *>(widget.get()) != nullptr) {*/
    /*        this->_displayClockWidget(*widget);*/
    /*        return;*/
    /*    }*/
    /*    if (dynamic_cast<Krell::Widgets::RangedWidget *>(widget.get()) != nullptr) {*/
    /*        this->_displayRangedWidget(*widget);*/
    /*        return;*/
    /*    }*/
    /*    if (dynamic_cast<Krell::Widgets::NumericWidget *>(widget.get()) != nullptr) {*/
    /*        this->_displayRangedWidget(*widget);*/
    /*        return;*/
    /*    if (dynamic_cast<Krell::Widgets::StringWidget *>(widget.get()) != nullptr) {*/
    /*        this->_displayRangedWidget(*widget);*/
    /*        return;*/
    /*    throw Error("Unknown module");*/
    /*}*/
}
