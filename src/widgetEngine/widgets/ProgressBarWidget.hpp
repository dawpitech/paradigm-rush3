/*
** EPITECH PROJECT, 2025
** paradigm-rush3
** File description:
** ProgressBarWidget.hpp
*/

#ifndef PROGRESSBARWIDGET_HPP
    #define PROGRESSBARWIDGET_HPP
    #define PROGRESSBAR_WIDTH 1

namespace Krell::Widgets
{
    class ProgressBarWidget final : public ValueWidget
    {
        public:
            ProgressBarWidget(const std::int32_t value, const std::string& legend)
                : ValueWidget(value, legend, PROGRESSBAR_WIDTH) {}
            ~ProgressBarWidget() override = default;
    };
}
#endif //PROGRESSBARWIDGET_HPP
