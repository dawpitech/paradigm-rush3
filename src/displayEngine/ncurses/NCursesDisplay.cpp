/*
** EPITECH PROJECT, 2025
** Rush 3
** File description:
** NCursesDisplay
*/

#include "NCursesDisplay.hpp"
#include "ncurses.h"
#include <iostream>
#include <vector>

void Krell::NCursesDisplay::printLayout(WINDOW *window, int width, std::string name)
{
    box(window, ACS_VLINE, ACS_HLINE);
    mvwprintw(window, 0, 5, " - ");
    mvwprintw(window, 0, width - 20, " %s ", name.c_str());
}

void Krell::NCursesDisplay::histogramContent(WINDOW *window, int width, int percentage)
{
    std::vector values = {77, 88 , 96, 78, 82, 70, 67, 99, 74, 85, 96 , 69, 12, 69, 99, 99, 99};
    int deplace = 0;
    int count = 0;

    for (int i = 0; count < values.size(); i++) {
        if (2 * i + 3 >= getmaxy(window)) {
            deplace += 18;
            i = 0;
        }
        count++;
        mvwprintw(window, 2 * i + 2, 4 + deplace, "CPU %i: %d%s", count, values[i], "%");
    }
    wrefresh(window);
}

void Krell::NCursesDisplay::progressBarContent(WINDOW *progressBar, int maxWidth, int percentage)
{
    for (size_t i = 4; i < maxWidth - 4; i++) {
        if (i < percentage * maxWidth / 100) {
            wattron(progressBar, COLOR_PAIR(1));
            mvwprintw(progressBar, 2, i, ":");
            wattroff(progressBar, COLOR_PAIR(1));
            } else {
                wattron(progressBar, COLOR_PAIR(5));
                mvwprintw(progressBar, 2, i, ":");
                wattroff(progressBar, COLOR_PAIR(5));
        }
    }
    wattron(progressBar, COLOR_PAIR(2));
    mvwprintw(progressBar, 1, 4, "RAM Usage %d%s", percentage, "%");
    wattroff(progressBar, COLOR_PAIR(2));
    wrefresh(progressBar);
}

void Krell::NCursesDisplay::gaugeContent(WINDOW *gauge, int maxWidth, int percentage)
{
    mvwprintw(gauge, 1, 4, "Battery");
    for (size_t i = 4; i < maxWidth - 4; i++) {
        if (i < percentage * maxWidth / 100) {
            wattron(gauge, COLOR_PAIR(4));
            mvwprintw(gauge, 2, i, " ");
            mvwprintw(gauge, 3, i, " ");
            mvwprintw(gauge, 4, i, " ");
            wattroff(gauge, COLOR_PAIR(4));
        } else {
            wattron(gauge, COLOR_PAIR(3));
            mvwprintw(gauge, 2, i, " ");
            mvwprintw(gauge, 3, i, " ");
            mvwprintw(gauge, 4, i, " ");
            wattroff(gauge, COLOR_PAIR(3));
        }
    }
    mvwprintw(gauge, 3, (maxWidth) / 2, "%d%s", percentage, "%");
    wrefresh(gauge);
}

void Krell::NCursesDisplay::stringContent(WINDOW *window, int maxWidth, int maxHeight)
{
    std::string username = "remy";
    std::string hostname = "rthai";
    std::string opSystem = "uwu client";
    std::string kernel = "kitty";
    std::string date = "11 February 2025";
    std::string time = "22:22";
    float increasing = 22.7;
    float decreasing = 18.9;

    mvwprintw(window, 1, maxWidth / 2 - 4 , "Username");
    wattron(window, COLOR_PAIR(2));
    mvwprintw(window, 2, maxWidth / 2 - username.length() / 2, "%s", username.c_str());
    wattroff(window, COLOR_PAIR(2));
    mvwprintw(window, 3, maxWidth / 2 - 4, "Hostname");
    wattron(window, COLOR_PAIR(2));
    mvwprintw(window, 4, maxWidth / 2 - hostname.length() / 2, "%s", hostname.c_str());
    wattroff(window, COLOR_PAIR(2));
    mvwprintw(window, 5, maxWidth / 2 - 8, "Operating System");
    wattron(window, COLOR_PAIR(2));
    mvwprintw(window, 6, maxWidth / 2 - opSystem.length() / 2, "%s", opSystem.c_str());
    wattroff(window, COLOR_PAIR(2));
    mvwprintw(window, 7, maxWidth / 2 - 3, "Kernel");
    wattron(window, COLOR_PAIR(2));
    mvwprintw(window, 8, maxWidth / 2 - kernel.length() / 2, "%s", kernel.c_str());
    wattroff(window, COLOR_PAIR(2));
    mvwprintw(window, 9, maxWidth / 2 - 2, "Date");
    wattron(window, COLOR_PAIR(2));
    mvwprintw(window, 10, maxWidth / 2 - date.length() / 2, "%s", date.c_str());
    wattroff(window, COLOR_PAIR(2));
    mvwprintw(window, 11, maxWidth / 2 - 2, "Time");
    wattron(window, COLOR_PAIR(2));
    mvwprintw(window, 12, maxWidth / 2 - time.length() / 2, "%s", time.c_str());
    wattroff(window, COLOR_PAIR(2));

    wattron(window, COLOR_PAIR(2));
    mvwprintw(window, maxHeight / 2, maxWidth / 4 - 8, "%f>", increasing);
    wattroff(window, COLOR_PAIR(2));

    wattron(window, COLOR_PAIR(2));
    mvwprintw(window, maxHeight / 2, maxWidth / 4 * 3, "%f<", decreasing);
    wattroff(window, COLOR_PAIR(2));

    wrefresh(window);
}

Krell::NCursesDisplay::NCursesDisplay()
{
    MEVENT event;

    int height;
    int width;
    initscr();
    getmaxyx(stdscr, height, width);
    start_color();

    WINDOW *histogram = subwin(stdscr, 17, width, 1, 0);
    WINDOW *progressBar = subwin(stdscr, 5, width, 18, 0);
    WINDOW *gauge = subwin(stdscr, 7, width, 23, 0);
    WINDOW *string = subwin(stdscr, 15, width, 30, 0);

    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    cbreak();
    mousemask(ALL_MOUSE_EVENTS, NULL);

    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_BLACK, COLOR_WHITE);
    init_pair(4, COLOR_BLACK, COLOR_GREEN);
    init_pair(5, COLOR_WHITE, COLOR_BLACK);

    time_t rawtime;
    time(&rawtime);

    printLayout(histogram, width, "Histogram");
    printLayout(progressBar, width, "Progress Bar");
    printLayout(gauge, width, "Gauge");
    printLayout(string, width, "String");

    progressBarContent(progressBar, width, 78);
    gaugeContent(gauge, width, 88);
    stringContent(string, width, getmaxy(string));
    histogramContent(histogram, width, 78);
    mvprintw(0, 2, "X");
    while (1) {
        time(&rawtime);
        this->_mouseEvent = wgetch(stdscr);
        if (getch() == 'q') {
            endwin();
            return;
        }
        progressBarContent(progressBar, width, 78);
        gaugeContent(gauge, width, 22);
        histogramContent(histogram, width, 78);
        if (this->_mouseEvent == KEY_MOUSE) {
            if (getmouse(&event) == OK) {
                if ((mvinch(event.y, event.x) == 'X') && BUTTON1_CLICKED) {
                    endwin();
                    return;
                }
                if ((mvwinch(histogram, 0, event.x) == '-') && BUTTON1_CLICKED) {
                    mvwprintw(histogram, 0, event.x, "+");
                    wresize(histogram, 3, width);
                    wrefresh(histogram);
                    refresh();
                }
                if ((mvwinch(progressBar, 0, event.x) == '-') && BUTTON1_CLICKED) {
                    mvwprintw(progressBar, 0, event.x, "+");
                    wresize(progressBar, 3, width);
                    wrefresh(progressBar);
                    refresh();
                }
                if ((mvwinch(gauge, 0, event.x) == '-') && BUTTON1_CLICKED) {
                    mvwprintw(gauge, 0, event.x, "+");
                    wresize(gauge, 3, width);
                    wrefresh(gauge);
                    refresh();
                }
                if ((mvwinch(string, 0, event.x) == '-') && BUTTON1_CLICKED) {
                    mvwprintw(string, 0, event.x, "+");
                    wresize(string, 3, width);
                    wrefresh(string);
                    refresh();
                }
                refresh();
            }
            refresh();
        }
        refresh();
    }
    endwin();
}

int main(void)
{
    Krell::NCursesDisplay display;
}