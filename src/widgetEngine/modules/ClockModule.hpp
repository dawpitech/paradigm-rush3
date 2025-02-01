/*
** EPITECH PROJECT, 2025
** paradigm-rush3
** File description:
** ClockModule.hpp
*/

#ifndef CLOCKMODULE_HPP
    #define CLOCKMODULE_HPP

    #define TIME_PLACEHOLDER "xx:xx:xx"
    #define DATE_PLACEHOLDER "xx/xx/xxxx"

#include "AModule.hpp"

namespace Krell::Modules
{
    class ClockModule final : public AModule
    {
        public:
            explicit ClockModule();
            void update() const override;

        protected:
    };
}
#endif //CLOCKMODULE_HPP
