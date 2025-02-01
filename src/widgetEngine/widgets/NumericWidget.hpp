/*
** EPITECH PROJECT, 2025
** paradigm-rush3
** File description:
** NumericWidget.hpp
*/

#ifndef NUMERICWIDGET_HPP
    #define NUMERICWIDGET_HPP

#include "AWidget.hpp"

namespace Krell::Widgets
{
    class NumericWidget : public AWidget
    {
        public:
            NumericWidget(const std::string& legend, const std::int32_t value)
            {
                this->_legend = legend;
                this->_value = value;
                this->_renderSize = 1;
            }
            ~NumericWidget() override = default;
            [[nodiscard]] std::int32_t getValue() const { return this->_value; }
            void setValue(const std::int32_t value) { this->_value = value; }

        protected:
            std::int32_t _value = -1;
    };
}
#endif //NUMERICWIDGET_HPP
