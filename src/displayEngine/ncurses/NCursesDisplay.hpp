/*
** EPITECH PROJECT, 2025
** Rush 3
** File description:
** NCursesDisplay
*/

#pragma once

#include <algorithm>
#include <ncurses.h>

#include "displayEngine/IDisplay.hpp"
#include "widgetEngine/widgets/NumericWidget.hpp"
#include "widgetEngine/widgets/StringWidget.hpp"

namespace Krell::Displays
{
    class NCursesDisplay final : public IDisplay
    {
        public:
            explicit NCursesDisplay();
            ~NCursesDisplay() override;
            void displayModules(
                std::shared_ptr<std::vector<std::shared_ptr<IModule>>> modules
            ) const override;
            bool useEvent() override;
            void _refresh() const override;

        protected:
            static void _renderWidget(const std::shared_ptr<IWidget>& widget,
                WINDOW* window,
                std::uint8_t x,
                std::uint8_t y);
            static void _renderStringWidget(const Widgets::StringWidget* widget,
                WINDOW* window,
                std::uint8_t x,
                std::uint8_t y);
            static void _renderNumericWidget(const Widgets::NumericWidget* widget,
                WINDOW* window,
                std::uint8_t x,
                std::uint8_t y);
    };
}
