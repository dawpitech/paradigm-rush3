/*
** EPITECH PROJECT, 2025
** paradigm-rush3
** File description:
** IWidget.hpp
*/

#ifndef IWIDGET_HPP
    #define IWIDGET_HPP

    #include <iostream>

namespace Krell
{
    class IWidget
    {
        public:
            virtual ~IWidget() = default;
            [[nodiscard]] virtual std::uint8_t getPos() const = 0;
            virtual void setPos(std::uint8_t) = 0;
            [[nodiscard]] virtual std::string getLegend() const = 0;
            [[nodiscard]] virtual std::size_t getRenderSize() const = 0;

        protected:
            std::uint8_t _pos;
            std::string _legend;
            std::size_t _renderSize = 0;
    };
};
#endif //IWIDGET_HPP
