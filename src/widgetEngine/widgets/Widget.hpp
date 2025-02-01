/*
** EPITECH PROJECT, 2025
** paradigm-rush3
** File description:
** Widget.hpp
*/

#ifndef WIDGET_HPP
    #define WIDGET_HPP

    #include "widgetEngine/IWidget.hpp"

namespace Krell::Widgets
{
    class Widget : public IWidget
    {
        public:
            Widget(const std::int32_t value, const std::string& legend,
                const std::size_t renderSize = 1)
            {
                this->_value = value;
                this->_legend = legend;
                this->_renderSize = renderSize;
            }
            ~Widget() override = default;
            std::int32_t getValue() override { return this->_value; }
            void setValue(const std::int32_t value) override { this->_value = value; }
            std::string getLegend() override { return this->_legend; }
            std::size_t getRenderSize() override { return this->_renderSize; }
    };
}
#endif //WIDGET_HPP
