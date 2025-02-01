/*
** EPITECH PROJECT, 2025
** paradigm-rush3
** File description:
** WidgetEngine.hpp
*/

#ifndef WIDGETENGINE_HPP
    #define WIDGETENGINE_HPP

    #include "modules/IModule.hpp"

class WidgetEngine
{
    public:
        explicit WidgetEngine();
        void refreshData() const;
        [[nodiscard]] std::shared_ptr<std::vector<std::shared_ptr<Krell::IModule>>>
            getModules() const { return this->_modules; }

    protected:
        std::shared_ptr<std::vector<std::shared_ptr<Krell::IModule>>> _modules;
};
#endif //WIDGETENGINE_HPP
