//
// EPITECH PROJECT, 2025
// App
// File description:
// Orchestrator for our GKrellM
//

#pragma once

#include "displayEngine/IDisplay.hpp"
#include "enums.hpp"
#include "widgetEngine/WidgetEngine.hpp"
#include <cstdint>
#include <exception>
#include <memory>
#include <string>

namespace Krell {

    class App {
        public:
            explicit App(const DisplayType &type);

            bool retrieveType(int argc, char **argv);
            [[noreturn]] int run();

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
            std::shared_ptr<std::vector<IModule>> _sortModules(
                std::shared_ptr<std::vector<IModule>> modules);
            std::unique_ptr<IDisplay> _displayManager = nullptr;
            WidgetEngine _widgetEngine = WidgetEngine();
            DisplayType _displayType = DisplayType::NCURSES;
            std::uint16_t timeBetweenFrameMs = 2000;
    };
}  // namespace Krell
