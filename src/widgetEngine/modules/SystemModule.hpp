/*
** EPITECH PROJECT, 2025
** paradigm-rush3
** File description:
** SystemModule.hpp
*/

#ifndef SYSTEMMODULE_HPP
    #define SYSTEMMODULE_HPP

    #include "AModule.hpp"

namespace Krell::Modules
{
    class SystemModule : public AModule
    {
        public:
            explicit SystemModule();
            void update() const override;
    };
}
#endif //SYSTEMMODULE_HPP
