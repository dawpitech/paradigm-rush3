/*
** EPITECH PROJECT, 2025
** paradigm-rush3
** File description:
** ProgressBarWidget.hpp
*/

#ifndef PROGRESSBARWIDGET_HPP
    #define PROGRESSBARWIDGET_HPP
    #define PROGRESSBAR_MAX_HISTORY 128

    #include <array>

namespace Krell::Widgets
{
    class ProgressBarWidget : public AWidget
    {
    public:
        explicit ProgressBarWidget(const std::string& legend)
        {
            this->_legend = legend;
            this->_renderSize = 1;
            this->_history;
        }
        ~ProgressBarWidget() override = default;
        [[nodiscard]] std::int16_t getValue() const { return this->_history[0]; }
        void addValue(const std::int16_t value)
        {
            for (std::size_t idx = 1; idx < PROGRESSBAR_MAX_HISTORY; idx++)
                this->_history[idx] = this->_history[idx - 1];
            this->_history[0] = value;
        }
        [[nodiscard]] std::array<std::int16_t, PROGRESSBAR_MAX_HISTORY> getHistory() const
            { return this->_history; }

    protected:
        std::array<std::int16_t, PROGRESSBAR_MAX_HISTORY> _history{};
    };
}
#endif //PROGRESSBARWIDGET_HPP
