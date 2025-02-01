//
// EPITECH PROJECT, 2025
// App
// File description:
// Orchestrator for our GKrellM
//

#pragma once

#include "displayEngine/IDisplay.hpp"
#include "widgetEngine/IModule.hpp"
#include <cstdint>
#include <exception>
#include <memory>
#include <string>

namespace Krell {

    enum class DisplayType { NCURSES, SFML };

    class App {
       public:
        App();
        bool run(const DisplayType &type);

        class Error : public std::exception {
           public:
            Error(const std::string &msg) : _msg(msg) {};

            const char *what() const noexcept override
            {
                return this->_msg.c_str();
            };

           private:
            std::string _msg;
        };

       private:
        std::shared_ptr<std::vector<IModule>> _module = nullptr;
        std::shared_ptr<IDisplay> _displayManager = nullptr;
        DisplayType type = DisplayType::NCURSES;
        std::uint16_t timeBetweenFrameMs = 2000;
    };
}  // namespace Krell
