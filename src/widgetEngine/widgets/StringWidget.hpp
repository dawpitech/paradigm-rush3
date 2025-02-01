/*
** EPITECH PROJECT, 2025
** paradigm-rush3
** File description:
** StringWidget.hpp
*/

#ifndef STRINGWIDGET_HPP
    #define STRINGWIDGET_HPP

    #include "AWidget.hpp"

namespace Krell::Widgets
{
    class StringWidget : public AWidget
    {
        public:
            StringWidget(const std::string& legend, const std::string& value)
            {
                this->_legend = legend;
                this->_value = value;
                this->_renderSize = 1;
            }
            ~StringWidget() override = default;
            [[nodiscard]] std::string getValue() const { return this->_value; }
            void setValue(std::string value);

        protected:
            std::string _value = {};
    };
}
#endif //STRINGWIDGET_HPP
