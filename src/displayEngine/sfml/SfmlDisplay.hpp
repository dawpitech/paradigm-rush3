//
// EPITECH PROJECT, 2025
// SfmlDisplay
// File description:
// display engine for sfml
//

#pragma once
#include "displayEngine/ADisplay.hpp"
#include "widgetEngine/widgets/IWidget.hpp"
#include <cstdio>

namespace Krell {
    class SfmlDisplay : public ADisplay {

       public:
        SfmlDisplay();
        ~SfmlDisplay() {};

        void useEvent() override;
        void moveWidget() override {};
        void removeWidget() override {};
        void minimizeWidget() override {};
        void useAction() {};

       private:
        virtual void _displayBaseModule(
            const IModule &module) const override;
        virtual void _displayHistogramWidget(
            const IWidget &widget) const override {};
        virtual void _displayProgressBarWidget(
            const IWidget &widget) const override {};
        virtual void _displayClockWidget(
            const IWidget &widget) const override {};
        virtual void _displayRangedWidget(
            const IWidget &widget) const override {};
        virtual void _displayNumericWidget(
            const IWidget &widget) const override {};
        virtual void _displayStringWidget(const IWidget &widget) const override;
        const std::size_t _frameLimit = 60;
        bool _init() override;
        bool _checkEnv() const override;
        std::uint8_t _nbModules = 5;
    };
}  // namespace Krell
