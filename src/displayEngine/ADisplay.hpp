//
// EPITECH PROJECT, 2025
// ADisplay
// File description:
// Abstract class for display
//

#pragma once

#include "displayEngine/IDisplay.hpp"
#include "enums.hpp"
#include "widgetEngine/IModule.hpp"
#include "displayEngine/IDisplay.hpp"
#include <memory>
#include <vector>

namespace Krell {
    class ADisplay : public IDisplay {
       public:
        virtual DisplayType displayModules(
            const std::shared_ptr<std::vector<std::unique_ptr<IModule>>> modules) const override;

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
        virtual void _displayBaseModule(const IModule &module) const override;
        virtual void _displayWidgets(const IModule &module) const override;
        virtual void _displayHistogramWidget(
            const IModule &module) const override;
        virtual void _displayProgressBarWidget(
            const IModule &module) const override;
        virtual void _displayClockWidget(
            const IModule &module) const override;
        virtual void _displayRangedWidget(
            const IModule &module) const override;
    };
}  // namespace Krell
