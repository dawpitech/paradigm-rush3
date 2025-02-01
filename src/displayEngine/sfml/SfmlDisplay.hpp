//
// EPITECH PROJECT, 2025
// SfmlDisplay
// File description:
// display engine for sfml
//

#pragma once

#include <cstdint>

#include "displayEngine/IDisplay.hpp"

namespace Krell {
    class SfmlDisplay final : public IDisplay {

        public:
            SfmlDisplay();
            ~SfmlDisplay() override = default;

            void useEvent() override;
            void displayModules(std::shared_ptr<std::vector<std::shared_ptr<IModule>>> module)
                const override;
            void _refresh() const override;

        private:
            bool _init();
            bool _checkEnv() const;
            void _displayStringWidget(const IWidget& widget, std::uint8_t pos) const;
            void _displayProgressBarWidget(const IWidget& widget, std::uint8_t pos) const;
            void _displayClockModule(const IModule& module) const;
            void _displayBaseModule(const IModule& module) const;
            void _clear() const;
            std::uint8_t _nbModules = 5;
            std::uint32_t _sizeX = 400;
            std::uint32_t _sizeY = 800;
            std::uint8_t _frameLimit = 1;
    };
}  // namespace Krell
