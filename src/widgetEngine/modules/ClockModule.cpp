/*
** EPITECH PROJECT, 2025
** paradigm-rush3
** File description:
** ClockModule.cpp
*/


#include <chrono>
#include <format>

#include "ClockModule.hpp"
#include "widgetEngine/widgets/StringWidget.hpp"

Krell::Modules::ClockModule::ClockModule()
{
    this->_render_name = std::string("Clock");

    this->_widgets.push_back(std::make_unique<Widgets::StringWidget>
        ("Date:", DATE_PLACEHOLDER));
    this->_widgets.push_back(std::make_unique<Widgets::StringWidget>
        ("Time:", TIME_PLACEHOLDER));
    this->update();
}

void Krell::Modules::ClockModule::update() const
{
    const auto now = std::chrono::system_clock::now();
    const auto t = std::chrono::system_clock::to_time_t(now);
    const auto local_time = std::localtime(&t);

    const auto renderedTime = std::format("{:02}:{:02}:{:02}",
        local_time->tm_hour,
        local_time->tm_min,
        local_time->tm_sec);

    std::ostringstream oss;
    oss << std::put_time(local_time, "%d/%m/%Y");

    dynamic_cast<Widgets::StringWidget*>(this->_widgets.at(0).get())->setValue(oss.str());
    dynamic_cast<Widgets::StringWidget*>(this->_widgets.at(1).get())->setValue(renderedTime);
}
