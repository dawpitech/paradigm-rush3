/*
** EPITECH PROJECT, 2025
** paradigm-rush3
** File description:
** HistogramWidget.hpp
*/

#ifndef HISTOGRAMWIDGET_HPP
    #define HISTOGRAMWIDGET_HPP
    #define HISTOGRAM_MAX_HISTORY 256

    #include <array>

    #include "widgetEngine/widgets/ValueWidget.hpp"

namespace Krell::Widgets
{
    class HistogramWidget final : public ValueWidget
    {
        public:
            HistogramWidget(const std::int32_t value, const std::string& legend,
                const std::size_t renderSize = 6)
                : ValueWidget(value, legend, renderSize) {}
            ~HistogramWidget() override = default;
            void addValue(const std::uint8_t value)
            {
                for (int idx = 1; idx < HISTOGRAM_MAX_HISTORY; idx++) {
                    this->_array[idx] = this->_array[idx - 1];
                }
                this->_array[0] = value;
            }

        private:
            std::array<std::uint8_t, HISTOGRAM_MAX_HISTORY> _array = {};
    };
};
#endif //HISTOGRAMWIDGET_HPP
