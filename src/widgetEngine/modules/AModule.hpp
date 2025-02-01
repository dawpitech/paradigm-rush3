/*
** EPITECH PROJECT, 2025
** paradigm-rush3
** File description:
** AModule.hpp
*/

#ifndef AMODULE_HPP
    #define AMODULE_HPP

    #include "IModule.hpp"

namespace Krell::Modules
{
    class AModule : public IModule
    {
        public:
            [[nodiscard]] std::vector<std::shared_ptr<IWidget>> getWidgets() const override
                { return this->_widgets; }
            //[[nodiscard]] std::shared_ptr<IWidget> getWidget(std::string legend) const override
            [[nodiscard]] std::string getRenderName() const override { return this->_render_name; }
            [[nodiscard]] std::size_t getRenderPos() const override { return this->_render_pos; }
            void setRenderPos(const std::size_t pos) override { this->_render_pos = pos; }
            [[nodiscard]] bool isActive() const override { return this->_active; }
            void setActive(const bool status) override { this->_active = status; }
    };
}
#endif //AMODULE_HPP
