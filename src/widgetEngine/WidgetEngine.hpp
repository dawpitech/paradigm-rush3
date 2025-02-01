/*
** EPITECH PROJECT, 2025
** paradigm-rush3
** File description:
** WidgetEngine.hpp
*/

#ifndef WIDGETENGINE_HPP
    #define WIDGETENGINE_HPP

    #include "IModule.hpp"

class WidgetEngine
{
    public:
        explicit WidgetEngine();
        void refreshData() const;
        std::shared_ptr<std::vector<std::unique_ptr<Krell::IModule>>>
            getModules() { return this->_modules; }

    protected:
        std::shared_ptr<std::vector<std::unique_ptr<Krell::IModule>>> _modules;
};
#endif //WIDGETENGINE_HPP
