//
// EPITECH PROJECT, 2025
// ADisplay
// File description:
// functions to display sfml
//

#include "ADisplay.hpp"
#include "widgetEngine/modules/ClockModule.hpp"
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
    this->_clear();
    for (auto &module : *modules) {
        if (!module)
            throw Error("Unable to access module");
        this->_displayBaseModule(*module);
        this->_displayWidgets(*module);
    }
    this->_refresh();
    return Krell::DisplayType::SFML;
}

//a suppr

void Krell::ADisplay::_displayWidgets(const IModule &module) const
{
    if (dynamic_cast<const Modules::ClockModule *>(&module)) {
        _displayClockModule(module);
        return;
    }
    auto widgets = module.getWidgets();

    for (size_t i = 0; i < widgets.size(); i += 1) {

        auto size = i * 25;
        /*if (dynamic_cast<Krell::Widgets::HistogramWidget *>(widget.get()) != nullptr) {*/
        /*    this->_displayHistogramWidget(*widgets[i]);*/
        /*    continue;*/
        /*}*/
        /*if (dynamic_cast<Krell::Widgets::ProgressBarWidget *>(widgets[i].get()) != nullptr) {*/
        /*    this->_displayProgressBarWidget(*widgets[i]);*/
        /*    continue;*/
        /*}*/
        /*if (dynamic_cast<Krell::Widgets::ClockWidget *>(widgets[i].get()) != nullptr) {*/
        /*    this->_displayClockWidget(*widgets[i], size);*/
        /*    continue;*/
        /*}*/
        /*if (dynamic_cast<Krell::Widgets::RangedWidget *>(widgets[i].get()) != nullptr) {*/
        /*    this->_displayRangedWidget(*widgets[i]);*/
        /*    continue;*/
        /*}*/
        /*if (dynamic_cast<Krell::Widgets::NumericWidget *>(widgets[i].get()) != nullptr) {*/
        /*    this->_displayNumericWidget(*widgets[i]);*/
        /*    continue;*/
        /*}*/
        if (dynamic_cast<Krell::Widgets::StringWidget *>(widgets[i].get()) != nullptr) {
            this->_displayStringWidget(*widgets[i], size);
            continue;
        }
        throw Error("Unknown module");
    }
}
