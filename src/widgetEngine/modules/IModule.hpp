/*
** EPITECH PROJECT, 2025
** paradigm-rush3
** File description:
** IModule.hpp
*/

#ifndef IMODULE_HPP
    #define IMODULE_HPP

    #include <memory>
    #include <string>
    #include <vector>

    #include "../widgets/IWidget.hpp"

namespace Krell
{
    class IModule
    {
        public:
            virtual ~IModule() = default;
            [[nodiscard]] virtual std::vector<std::shared_ptr<IWidget>> getWidgets() const = 0;
            //[[nodiscard]] virtual std::shared_ptr<IWidget> getWidget(std::string legend) const = 0;
            [[nodiscard]] virtual std::string getRenderName() const = 0;
            [[nodiscard]] virtual std::size_t getRenderPos() const = 0;
            virtual void setRenderPos(std::size_t pos) = 0;
            [[nodiscard]] virtual bool isActive() const = 0;
            virtual void setActive(bool status) = 0;
            virtual void update() const = 0;

        protected:
            std::vector<std::shared_ptr<IWidget>> _widgets;
            std::string _render_name = {};
            std::size_t _render_pos = 0;
            bool _active = false;
    };
};
#endif //IMODULE_HPP
