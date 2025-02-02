//
// EPITECH PROJECT, 2025
// IDisplay
// File description:
// Interface for display engine
//

#pragma once

#include <memory>
#include <vector>

#include "enums.hpp"
#include "widgetEngine/modules/IModule.hpp"

namespace Krell {
    class IDisplay {
        public:
            virtual ~IDisplay() = default;
            virtual void displayModules(
                std::shared_ptr<std::vector<std::shared_ptr<IModule>>> module
            ) const = 0;
            virtual bool useEvent() = 0;
            virtual void _refresh() const = 0;
    };
}  // namespace Krell
