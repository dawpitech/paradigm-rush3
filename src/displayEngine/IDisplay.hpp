//
// EPITECH PROJECT, 2025
// IDisplay
// File description:
// Interface for display engine
//

#pragma once

#include "widgetEngine/IModule.hpp"
#include "widgetEngine/IWidget.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <cstdint>
#include <memory>
#include <vector>

namespace Krell {
    class IDisplay {
       public:
        virtual void displayModules(const std::vector<IModule> &modules) const = 0;
        virtual void moveWidget() = 0;
        virtual void removeWidget() = 0;
        virtual void minimizeWidget() = 0;

       protected:
        virtual bool _checkEnv() const = 0;
        virtual bool _init() = 0;
        virtual void _displayBaseModule(const IModule &module) const = 0;
        virtual void _displayWidgets(const IModule &module) const = 0;
        virtual void _displayHistogramWidget(const IModule &module) const = 0;
        const std::uint32_t _sizeX = 800;
        const std::uint32_t _sizeY = 200;
        std::shared_ptr<sf::RenderWindow> _window;
    };
}  // namespace Krell
