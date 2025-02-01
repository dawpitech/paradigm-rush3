/*
** EPITECH PROJECT, 2025
** paradigm-rush3
** File description:
** StringWidget.hpp
*/

#ifndef STRINGWIDGET_HPP
    #define STRINGWIDGET_HPP

    #include "widgetEngine/IWidget.hpp"

namespace Krell::Widgets
{
    class StringWidget final : public IWidget
    {
    public:
        StringWidget(const std::string& value, const std::string& legend,
            const std::size_t renderSize = 1)
        {
            this->_value = value;
            this->_legend = legend;
            this->_renderSize = renderSize;
        }
        ~StringWidget() override = default;
        std::string getValue() const { return this->_value; }
        void setValue(const std::string& value) { this->_value = value; }
        std::string getLegend() override { return this->_legend; }
        std::size_t getRenderSize() override { return this->_renderSize; }

        protected:
            std::string _value = {};
    };
}
#endif //STRINGWIDGET_HPP
