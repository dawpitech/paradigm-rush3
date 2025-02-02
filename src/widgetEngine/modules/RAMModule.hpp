/*
** EPITECH PROJECT, 2025
** paradigm-rush3
** File description:
** RAMModule.hpp
*/

#ifndef RAMMODULE_HPP
    #define RAMMODULE_HPP

    #define RAM_MAX_PLACEHOLDER 16000000
    #define RAM_FREE_PLACEHOLDER  8000000

    #include "AModule.hpp"

namespace Krell::Modules
{
    class RAMModule final : public AModule
    {
        public:
            explicit RAMModule();
            void update() const override;

        protected:
            static std::uint32_t getMaxMem();
            static std::uint32_t getFreeMem();
    };
}
#endif //RAMMODULE_HPP
