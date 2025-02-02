/*
** EPITECH PROJECT, 2025
** Rush 3
** File description:
** NCursesDisplay
*/

#include <ncurses.h>

#include "NCursesDisplay.hpp"

Krell::Displays::NCursesDisplay::NCursesDisplay()
{
    initscr();
    curs_set(0);
    noecho();
}

Krell::Displays::NCursesDisplay::~NCursesDisplay()
{
    endwin();
}

void Krell::Displays::NCursesDisplay::displayModules(
    const std::shared_ptr<std::vector<std::shared_ptr<IModule>>> modules) const
{
    int height;
    int width;
    getmaxyx(stdscr, height, width);
    (void) height;

    clear();
    std::uint8_t current_y_pos = 0;
    for (const auto& module : *modules)
    {
        std::uint8_t y_rendering_height = 0;
        for (const auto& widget : module->getWidgets())
            y_rendering_height += widget->getRenderSize();

        y_rendering_height = std::clamp(
            y_rendering_height,
            static_cast<uint8_t>(0),
            static_cast<uint8_t>(64)
        );
        WINDOW* module_window = subwin(stdscr, y_rendering_height + 2, width, current_y_pos, 0);

        box(module_window, ACS_VLINE, ACS_HLINE);
        mvwprintw(module_window, 0, 10, "| %s |", module->getRenderName().c_str());

        std::uint8_t current_rendering_y = 1;
        for (const auto& widget : module->getWidgets()) {
            _renderWidget(widget, module_window, width / 2 - width * 0.10, current_rendering_y);
            current_rendering_y += widget->getRenderSize();
        }

        current_y_pos += 2 + y_rendering_height;
    }
    refresh();
}

void Krell::Displays::NCursesDisplay::_renderWidget(
    const std::shared_ptr<IWidget>& widget,
    WINDOW* window,
    const std::uint8_t x,
    const std::uint8_t y)
{
    if (dynamic_cast<Widgets::StringWidget*>(widget.get()) != nullptr)
        return _renderStringWidget(
            dynamic_cast<Widgets::StringWidget*>(widget.get()),
            window, x, y);
    if (dynamic_cast<Widgets::NumericWidget*>(widget.get()) != nullptr)
        return _renderNumericWidget(
            dynamic_cast<Widgets::NumericWidget*>(widget.get()),
            window, x, y);
}

void Krell::Displays::NCursesDisplay::_renderStringWidget(
    const Widgets::StringWidget* widget,
    WINDOW* window,
    const std::uint8_t x,
    const std::uint8_t y)
{
    mvwprintw(window, y, x, "%s %s",
        widget->getLegend().c_str(),
        widget->getValue().c_str());
}

void Krell::Displays::NCursesDisplay::_renderNumericWidget(
    const Widgets::NumericWidget* widget,
    WINDOW* window,
    const std::uint8_t x,
    const std::uint8_t y)
{
    mvwprintw(window, y, x, "%s %u",
        widget->getLegend().c_str(),
        widget->getValue());
}

void Krell::Displays::NCursesDisplay::useEvent()
{
}

void Krell::Displays::NCursesDisplay::_refresh() const
{
}
