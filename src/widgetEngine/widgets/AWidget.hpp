/*
** EPITECH PROJECT, 2025
** paradigm-rush3
** File description:
** AWidget.hpp
*/

#ifndef AWIDGET_HPP
    #define AWIDGET_HPP

    #include "IWidget.hpp"

namespace Krell::Widgets
{
    class AWidget : public IWidget
    {
        public:
            [[nodiscard]] std::uint8_t getPos() const override { return this->_pos; }
            void setPos(const std::uint8_t pos) override { this->_pos = pos; }
            [[nodiscard]] std::string getLegend() const override { return this->_legend; }
            [[nodiscard]] std::size_t getRenderSize() const override { return this->_renderSize; }
    };
}
#endif //AWIDGET_HPP
