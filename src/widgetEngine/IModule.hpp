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

namespace Krell {
    class IModule {
       public:
        enum class ModuleType {
            UNKNOWN,
            BATTERY,
            SYSTEM,
            CPU,
            RAM,
        };
        virtual std::shared_ptr<std::vector<IWidget &>> getWidgets() = 0;
        virtual ModuleType getType() = 0;
        virtual std::string getRenderName() = 0;
        virtual std::size_t getRenderPos() = 0;
        virtual void setRenderPos() = 0;
        virtual bool isActive() = 0;
        virtual void setActive() = 0;

       protected:
        std::shared_ptr<std::vector<IWidget &>> _widgets = nullptr;
        ModuleType _type = ModuleType::UNKNOWN;
        std::string _render_name = {};
        std::size_t _render_pos = 0;
        bool _active = false;
    };
};  // namespace Krell
#endif  //IMODULE_HPP
