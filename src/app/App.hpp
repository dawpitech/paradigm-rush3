//
// EPITECH PROJECT, 2025
// App
// File description:
// Orchestrator for our GKrellM
//

#pragma once

#include <cstdint>
#include <memory>

#include "enums.hpp"
#include "displayEngine/IDisplay.hpp"
#include "widgetEngine/WidgetEngine.hpp"

namespace Krell {

    class App {
        public:
            explicit App(const DisplayType &type);

            void run();

        private:
            std::unique_ptr<IDisplay> _displayManager = nullptr;
            WidgetEngine _widgetEngine = WidgetEngine();
            DisplayType _displayType;
            std::uint16_t timeBetweenFrameMs = 2000;
    };
}  // namespace Krell
