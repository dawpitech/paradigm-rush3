//
// EPITECH PROJECT, 2025
// ADisplay
// File description:
// functions to display sfml
//

#include "ADisplay.hpp"
#include "widgetEngine/IModule.hpp"
#include "enums.hpp"
#include <memory>

Krell::DisplayType Krell::ADisplay::displayModules(
            const std::shared_ptr<std::vector<std::unique_ptr<IModule>>> modules) const
{
    for (auto &module : *modules) {
        this->_displayWidgets(*module);
    }
    return Krell::DisplayType::SFML;
}

void Krell::ADisplay::_displayWidgets(const IModule &module) const
{
    for (auto widget : module.getWidgets()) {
        if (dynamic_cast<HistogramWidget>(widget) != nullptr) {
            this->_displayHistogramWidget(widget);
            return;
        }
        if (dynamic_cast<ProgressBarWidget>(widget) != nullptr) {
            this->_displayProgressBarWidget(widget);
            return;
        }
        if (dynamic_cast<ClockWidget>(widget) != nullptr) {
            this->_displayClockWidget(widget);
            return;
        }
        if (dynamic_cast<RangedWidget>(widget) != nullptr) {
            this->_displayRangedWidget(widget);
            return;
        }
        throw Error("Unknown module");
    }
}
