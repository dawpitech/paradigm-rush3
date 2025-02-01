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

namespace Krell
{
    class IWidget
    {
        public:
            virtual ~IWidget() = 0;
            virtual std::int32_t getValue() = 0;
            virtual void setValue(std::int32_t value) = 0;
            virtual std::string getLegend() = 0;
            virtual std::size_t getRenderSize() = 0;

        protected:
            std::int32_t _value = -1;
            std::string _legend;
            std::size_t _renderSize = 0;
    };
};
#endif //IWIDGET_HPP
