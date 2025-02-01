//
// EPITECH PROJECT, 2025
// SfmlDisplay
// File description:
// display engine for sfml
//

#pragma once
#include "displayEngine/IDisplay.hpp"
#include <cstdio>
#include <exception>
#include <string>

class SfmlDisplay : public IDisplay {

   public:
    SfmlDisplay();
    ~SfmlDisplay()  {};

    void displayWidget() override {};
    void moveWidget() override {};
    void removeWidget() override {};
    void minimizeWidget() override {};

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
    const std::size_t _frameLimit = 60;
    bool _init();
    bool _checkEnv() const override;
};
