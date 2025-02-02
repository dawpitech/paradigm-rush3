/*
** EPITECH PROJECT, 2025
** paradigm-rush3
** File description:
** RAMModule.cpp
*/

#include <fstream>
#include <sstream>

#include "RAMModule.hpp"
#include "widgetEngine/Exceptions.hpp"
#include "widgetEngine/widgets/NumericWidget.hpp"

Krell::Modules::RAMModule::RAMModule()
{
    this->_render_name = std::string("RAM Stats");

    std::uint32_t ramMax = RAM_MAX_PLACEHOLDER;
    std::uint32_t ramFree = RAM_FREE_PLACEHOLDER;

    try {
        ramMax = getMaxMem();
        ramFree = getFreeMem();
    } catch (const Widgets::Exceptions::GenericWidgetException& e) {
        std::cerr << e.what() << std::endl;
    }

    this->_widgets.push_back(std::make_unique<Widgets::NumericWidget>
        ("Available (Mib):", ramMax));
    this->_widgets.push_back(std::make_unique<Widgets::NumericWidget>
        ("Free (Mib):", ramFree));
}

void Krell::Modules::RAMModule::update() const
{
    dynamic_cast<Widgets::NumericWidget*>(this->_widgets.at(0).get())
        ->setValue(static_cast<int32_t>(getMaxMem()));
    dynamic_cast<Widgets::NumericWidget*>(this->_widgets.at(1).get())
        ->setValue(static_cast<int32_t>(getFreeMem()));
}


std::uint32_t Krell::Modules::RAMModule::getMaxMem()
{
    std::ifstream file_stream("/proc/meminfo", std::ios::in);

    if (!file_stream.is_open())
        throw Widgets::Exceptions::NoSystemAccess();
    std::stringstream content_buffer;
    content_buffer << file_stream.rdbuf();
    file_stream.close();

    std::string line;
    file_stream.close();

    bool empty_line = false;
    while (std::getline(content_buffer, line, '\n'))
    {
        std::stringstream line_content(line);
        std::string temp_str;
        bool should_keep = false;
        while (std::getline(line_content, temp_str, ':'))
        {
            if (should_keep)
                return std::stoul(temp_str);
            if (temp_str.starts_with("MemTotal"))
                should_keep = true;
        }
        if (line.empty() && empty_line)
            break;
        if (line.empty())
            empty_line = true;
    }
    return RAM_MAX_PLACEHOLDER;
}

std::uint32_t Krell::Modules::RAMModule::getFreeMem()
{
    std::ifstream file_stream("/proc/meminfo", std::ios::in);

    if (!file_stream.is_open())
        throw Widgets::Exceptions::NoSystemAccess();
    std::stringstream content_buffer;
    content_buffer << file_stream.rdbuf();
    file_stream.close();

    std::string line;
    file_stream.close();

    bool empty_line = false;
    while (std::getline(content_buffer, line, '\n'))
    {
        std::stringstream line_content(line);
        std::string temp_str;
        bool should_keep = false;
        while (std::getline(line_content, temp_str, ':'))
        {
            if (should_keep)
                return std::stoul(temp_str);
            if (temp_str.starts_with("MemFree"))
                should_keep = true;
        }
        if (line.empty() && empty_line)
            break;
        if (line.empty())
            empty_line = true;
    }
    return RAM_FREE_PLACEHOLDER;
}
