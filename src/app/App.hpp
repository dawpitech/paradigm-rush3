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

            void run() const;

        private:
            std::unique_ptr<IDisplay> _displayManager = nullptr;
            WidgetEngine _widgetEngine = WidgetEngine();
            DisplayType _displayType;
            std::uint16_t timeBetweenFrameMs = 2000;
    };
}  // namespace Krell
