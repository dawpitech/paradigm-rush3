//
// EPITECH PROJECT, 2025
// ADisplay
// File description:
// Abstract class for display
//

#pragma once

#include "IModule.hpp"
#include "IWidget.hpp"
#include "displayEngine/IDisplay.hpp"
#include <stdexcept>
#include <vector>

namespace Krell {
    class ADisplay : public IDisplay {
       public:
        virtual void displayModules(
            const std::vector<IModule> &modules) const override;

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
        virtual void _displayHistogramWidget(
            const IModule &module) const override;
    };
}  // namespace Krell
