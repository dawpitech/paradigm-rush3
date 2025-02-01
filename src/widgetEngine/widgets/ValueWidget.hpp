/*
** EPITECH PROJECT, 2025
** paradigm-rush3
** File description:
** ValueWidget.hpp
*/

#ifndef WIDGET_HPP
    #define WIDGET_HPP

    #include "widgetEngine/IWidget.hpp"

namespace Krell::Widgets
{
    class ValueWidget : public IWidget
    {
        public:
            ValueWidget(const std::int32_t value, const std::string& legend,
                const std::size_t renderSize = 1)
            {
                this->_value = value;
                this->_legend = legend;
                this->_renderSize = renderSize;
            }
            ~ValueWidget() override = default;
            std::int32_t getValue() const { return this->_value; }
            void setValue(const std::int32_t value) { this->_value = value; }
            std::string getLegend() override { return this->_legend; }
            std::size_t getRenderSize() override { return this->_renderSize; }

        protected:
            std::int32_t _value = -1;
    };
}
#endif //WIDGET_HPP
