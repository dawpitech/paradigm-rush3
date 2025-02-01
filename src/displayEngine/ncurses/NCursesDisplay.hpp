/*
** EPITECH PROJECT, 2025
** Rush 3
** File description:
** NCursesDisplay
*/

#include <cstdint>
#include <ncurses.h>
#include <iostream>

#pragma once

namespace Krell {

    class NCursesDisplay  {
        public:
            NCursesDisplay();
            ~NCursesDisplay() {};
            void printLayout(WINDOW *window, int width, std::string name);
            void stringContent(WINDOW *window, int maxWidth, int maxHeight);
            void gaugeContent(WINDOW *gauge, int maxWidth, int percentage);
            void progressBarContent(WINDOW *progressBar, int maxWidth, int percentage);
            void histogramContent(WINDOW *window, int width, int percentage);
            /* void displayWidget() override;
            void moveWidget() override;
            void removeWidget() override;
            void minimizeWidget() override; */

        private:
            int _mouseEvent;
           /*  bool _checkEnv() const override; */
    };

}
