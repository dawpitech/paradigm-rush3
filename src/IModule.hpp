/*
** EPITECH PROJECT, 2025
** paradigm-rush3
** File description:
** IModule.hpp
*/

#ifndef IMODULE_HPP
    #define IMODULE_HPP

    #include <string>
    #include <vector>

class IModule
{
    public:
        enum ModuleType
        {
            UNKNOWN,
            BATTERY,
            SYSTEM,
            CPU,
            RAM,
        };

    protected:
        std::vector<IModule> _widgets = {};
        ModuleType _type = UNKNOWN;
        std::string _render_name = {};
        std::size_t _render_pos = 0;
        bool _active = false;
};
#endif //IMODULE_HPP
