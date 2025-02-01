//
// EPITECH PROJECT, 2025
// ADisplay
// File description:
// functions to display sfml
//

#include "ADisplay.hpp"
#include "IModule.hpp"

void Krell::ADisplay::displayModules(const std::vector<IModule> &modules) const
{
    for (auto &module : modules) {
        this->_displayWidgets(module);
    }
}

void Krell::ADisplay::_displayWidgets(const IModule &module) const
{
    for (auto widget : module.getWidgets()) {
        if (dynamic_cast<HistogramWidget>(module) != nullptr) {
            this->_displayHistogramWidget(module);
            return;
        }
        if (dynamic_cast<ProgressBarWidget>(module) != nullptr) {
            this->_displayProgressBarWidget(module);
            return;
        }
        if (dynamic_cast<ClockWidget>(module) != nullptr) {
            this->_displayClockWidget(module);
            return;
        }
        if (dynamic_cast<RangedWidget>(module) != nullptr) {
            this->_displayRangedWidget(module);
            return;
        }
        throw Error("Unknown module");
    }
}
