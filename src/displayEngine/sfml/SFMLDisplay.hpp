//
// EPITECH PROJECT, 2025
// SfmlDisplay
// File description:
// display engine for sfml
//

#pragma once

#define SFML_PADDING 25
#define SML_BORDER_THICKNESS 5
#define SML_SIZE_FACTOR 15

#include <cstdint>
#include <SFML/Graphics.hpp>

#include "displayEngine/IDisplay.hpp"
#include "widgetEngine/widgets/NumericWidget.hpp"
#include "widgetEngine/widgets/StringWidget.hpp"

namespace Krell::Displays
{
    class SFMLDisplay final : public IDisplay {

        public:
            class UserCalledExitException final : public std::exception {};

            explicit SFMLDisplay();
            ~SFMLDisplay() override;
            void displayModules(
                std::shared_ptr<std::vector<std::shared_ptr<IModule>>> modules
            ) const override;
            void useEvent() override;
            void _refresh() const override;

        private:
            void _renderWidget(
                const std::shared_ptr<IWidget>& widget,
                std::uint16_t x,
                std::uint16_t y) const;
            void _renderStringWidget(
                const Widgets::StringWidget* widget,
                std::uint16_t x,
                std::uint16_t y) const;
            void _renderNumericWidget(
                const Widgets::NumericWidget* widget,
                std::uint16_t x,
                std::uint16_t y) const;
            std::shared_ptr<sf::RenderWindow> _window;
            std::unique_ptr<sf::Font> _font;
            std::uint8_t _nbModules = 5;
            std::uint32_t _sizeX = 700;
            std::uint32_t _sizeY = 1000;
            std::uint8_t _frameLimit = 30;
    };
}
