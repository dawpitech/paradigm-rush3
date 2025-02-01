//
// EPITECH PROJECT, 2025
// ADisplay
// File description:
// Abstract class for display
//

#pragma once

#include "displayEngine/IDisplay.hpp"
#include "enums.hpp"
#include "widgetEngine/modules/IModule.hpp"
#include "widgetEngine/widgets/IWidget.hpp"
#include <memory>
#include <vector>

namespace Krell {
    class ADisplay : public IDisplay {
       public:
        virtual DisplayType displayModules(
            const std::shared_ptr<std::vector<std::shared_ptr<IModule>>>
                modules) const override;

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

       protected:
        virtual void _displayWidgets(const IModule &module) const override;
    };
}  // namespace Krell
