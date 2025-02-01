/*
** EPITECH PROJECT, 2025
** paradigm-rush3
** File description:
** SystemModule.hpp
*/

#ifndef SYSTEMMODULE_HPP
    #define SYSTEMMODULE_HPP

#include "widgetEngine/IModule.hpp"

namespace Krell::Modules
{
    class SystemModule final : public IModule
    {
        public:
            SystemModule();
            ~SystemModule() override = default;
            std::shared_ptr<std::vector<IWidget>> getWidgets() override { return this->_widgets; }
            IWidget& getWidget(std::string legend) override;
            std::string getRenderName() override { return this->_render_name; }
            std::size_t getRenderPos() override { return this->_render_pos; }
            void setRenderPos(const std::size_t pos) override { this->_render_pos = pos; }
            bool isActive() override { return this->_active; }
            void setActive(const bool status) override { this->_active = status; }
            void update() override {}

        protected:
            void addModule(const IWidget& widget) override;
    };
};
#endif //SYSTEMMODULE_HPP
