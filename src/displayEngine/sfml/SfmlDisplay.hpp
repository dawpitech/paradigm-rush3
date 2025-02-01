//
// EPITECH PROJECT, 2025
// SfmlDisplay
// File description:
// display engine for sfml
//

#pragma once
#include "displayEngine/ADisplay.hpp"
#include <cstdio>
#include <exception>
#include <string>

namespace Krell {
    class SfmlDisplay : public ADisplay {

       public:
        SfmlDisplay();
        ~SfmlDisplay() {};

        void useEvent() override;
        void moveWidget() override {};
        void removeWidget() override {};
        void minimizeWidget() override {};
        void useAction() {};

       private:
        const std::size_t _frameLimit = 60;
        bool _init() override;
        bool _checkEnv() const override;
    };
}  // namespace Krell
