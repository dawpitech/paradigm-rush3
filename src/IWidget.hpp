/*
** EPITECH PROJECT, 2025
** paradigm-rush3
** File description:
** IWidget.hpp
*/

#ifndef IWIDGET_HPP
    #define IWIDGET_HPP

    #include <cstdint>
    #include <iostream>

class IWidget
{
    public:
        std::int32_t getValue();
        std::string getLegend();
        std::size_t getRenderSize();
};
#endif //IWIDGET_HPP
