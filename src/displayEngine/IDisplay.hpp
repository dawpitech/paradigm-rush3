//
// EPITECH PROJECT, 2025
// IDisplay
// File description:
// Interface for display engine
//

#pragma once

#include "enums.hpp"
#include "widgetEngine/modules/IModule.hpp"
#include "widgetEngine/widgets/IWidget.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <cstdint>
#include <memory>
#include <vector>

namespace Krell {
    class IDisplay {
       public:
        virtual DisplayType displayModules(
            const std::shared_ptr<std::vector<std::shared_ptr<IModule>>> modules) const = 0;
        virtual void useEvent() = 0;
        virtual void moveWidget() = 0;
        virtual void removeWidget() = 0;
        virtual void minimizeWidget() = 0;

       protected:
        virtual bool _checkEnv() const = 0;
        virtual bool _init() = 0;
        virtual void _displayBaseModule(const IModule &module) const = 0;
        virtual void _displayWidgets(const IModule &module) const = 0;
        virtual void _displayHistogramWidget(const IWidget &widget) const = 0;
        virtual void _displayProgressBarWidget(const IWidget &widget) const = 0;
        virtual void _displayClockWidget(const IWidget &widget) const = 0;
        virtual void _displayRangedWidget(const IWidget &widget) const = 0;
        virtual void _displayNumericWidget(const IWidget &widget) const = 0;
        virtual void _displayStringWidget(const IWidget &widget) const = 0;
        const std::uint32_t _sizeX = 200;
        const std::uint32_t _sizeY = 800;
        std::shared_ptr<sf::RenderWindow> _window;
    };
}  // namespace Krell
