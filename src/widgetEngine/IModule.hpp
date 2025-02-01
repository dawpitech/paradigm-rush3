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

    #include "IWidget.hpp"

namespace Krell
{
    class IModule
    {
        public:
            virtual ~IModule() = 0;
            virtual std::shared_ptr<std::vector<IWidget>> getWidgets() = 0;
            virtual IWidget& getWidget(std::string legend);
            virtual std::string getRenderName() = 0;
            virtual std::size_t getRenderPos() = 0;
            virtual void setRenderPos(std::size_t pos) = 0;
            virtual bool isActive() = 0;
            virtual void setActive(bool status) = 0;

        protected:
            virtual void addModule(const IWidget& widget) = 0;
            std::shared_ptr<std::vector<IWidget &>> _widgets = nullptr;
            std::string _render_name = {};
            std::size_t _render_pos = 0;
            bool _active = false;
    };
};
#endif //IMODULE_HPP
