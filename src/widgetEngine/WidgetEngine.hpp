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
        WidgetEngine();
        void update();
        std::vector<Krell::IModule&> getModules();

    protected:
        std::vector<Krell::IModule&> _modules;
};
#endif //WIDGETENGINE_HPP
