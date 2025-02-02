/*
** EPITECH PROJECT, 2025
** paradigm-rush3
** File description:
** SystemModule.cpp
*/

#include <array>
#include <fstream>
#include <sstream>
#include <sys/utsname.h>

#include "SystemModule.hpp"
#include "AModule.hpp"
#include "widgetEngine/Exceptions.hpp"
#include "widgetEngine/widgets/StringWidget.hpp"

Krell::Modules::SystemModule::SystemModule()
{
    this->_render_name = std::string("System Infos");

    std::array<char, 256> username_buff = {0};
    std::array<char, 256> hostname_buff = {0};
    std::string username = DEFAULT_FIELD_VALUE;
    std::string hostname = DEFAULT_FIELD_VALUE;
    std::string opSys = DEFAULT_FIELD_VALUE;
    std::string kernel = DEFAULT_FIELD_VALUE;

    try {
        getlogin_r(username_buff.begin(), 256);
        username = std::string(username_buff.data());
        gethostname(hostname_buff.begin(), 256);
        hostname = std::string(hostname_buff.data());
        opSys = getOpSys();
        kernel = getKernelVer();
    } catch (const Widgets::Exceptions::GenericWidgetException& e) {
        std::cerr << e.what() << std::endl;
    }

    this->_widgets.push_back(std::make_shared<Widgets::StringWidget>
        ("Username:", username));
    this->_widgets.push_back(std::make_shared<Widgets::StringWidget>
        ("Hostname:", hostname));
    this->_widgets.push_back(std::make_shared<Widgets::StringWidget>
        ("Op. sys.:", opSys));
    this->_widgets.push_back(std::make_shared<Widgets::StringWidget>
        ("Kernel:", kernel));
}

std::string Krell::Modules::SystemModule::getOpSys()
{
    std::ifstream file_stream(OS_RELEASE_PATH, std::ios::in | std::ios::ate);

    if (!file_stream.is_open())
        throw Widgets::Exceptions::NoSystemAccess();
    const auto size = file_stream.tellg();
    std::string str(size, '\0');
    file_stream.seekg(0);
    if (!file_stream.read(&str[0], size))
        throw Widgets::Exceptions::NoSystemAccess();

    std::stringstream lines(str);
    std::string line;
    file_stream.close();
    while (std::getline(lines, line, '\n'))
    {
        std::stringstream line_content(line);
        std::string temp_str;
        bool should_kelp = false;
        while (std::getline(line_content, temp_str, '='))
        {
            if (should_kelp)
            {
                std::erase(temp_str, '"');
                return temp_str;
            }
            if (temp_str == "PRETTY_NAME")
                should_kelp = true;
        }
    }
    return DEFAULT_FIELD_VALUE;
}

std::string Krell::Modules::SystemModule::getKernelVer()
{
    utsname systemInfos = {};
    if (uname(&systemInfos) == -1)
        throw Widgets::Exceptions::NoKernelInfoAccess();
    return std::string(systemInfos.sysname) + " " + std::string(systemInfos.release);
}
