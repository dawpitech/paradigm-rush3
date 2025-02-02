/*
** EPITECH PROJECT, 2025
** paradigm-rush3
** File description:
** CPUModule.cpp
*/

#include <fstream>
#include <sstream>

#include "CPUModule.hpp"
#include "widgetEngine/Exceptions.hpp"
#include "widgetEngine/widgets/NumericWidget.hpp"
#include "widgetEngine/widgets/StringWidget.hpp"

Krell::Modules::CPUModule::CPUModule()
{
    this->_render_name = std::string("CPU Stats");

    std::string cpuName = CPU_NAME_PLACEHOLDER;
    std::uint32_t cpuFreq = CPU_FREQ_PLACEHOLDER;

    try {
        cpuName = getCPUName();
        cpuFreq = getFreq();
    } catch (const Widgets::Exceptions::GenericWidgetException& e) {
        std::cerr << e.what() << std::endl;
    }

    this->_widgets.push_back(std::make_unique<Widgets::StringWidget>
        ("CPU:", cpuName));
    this->_widgets.push_back(std::make_unique<Widgets::NumericWidget>
        ("Freq. (MHz):", cpuFreq));
}

void Krell::Modules::CPUModule::update() const
{
    dynamic_cast<Widgets::NumericWidget*>(this->_widgets.at(1).get())
        ->setValue(static_cast<int32_t>(getFreq()));
}

std::string Krell::Modules::CPUModule::getCPUName()
{
    std::ifstream file_stream("/proc/cpuinfo", std::ios::in);

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
                return &temp_str[1];
            if (temp_str.starts_with("model name"))
                should_keep = true;
        }
        if (line.empty() && empty_line)
            break;
        if (line.empty())
            empty_line = true;
    }
    return CPU_NAME_PLACEHOLDER;
}

std::uint32_t Krell::Modules::CPUModule::getFreq()
{
    std::ifstream file_stream("/proc/cpuinfo", std::ios::in);

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
            if (temp_str.starts_with("cpu MHz"))
                should_keep = true;
        }
        if (line.empty() && empty_line)
            break;
        if (line.empty())
            empty_line = true;
    }
    return CPU_FREQ_PLACEHOLDER;
}
