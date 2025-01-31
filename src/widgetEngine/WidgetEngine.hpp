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
        void update();
        std::vector<IModule&> getModules();

    protected:
        std::vector<IModule&> _modules;
};
#endif //WIDGETENGINE_HPP
