/*
** EPITECH PROJECT, 2025
** paradigm-rush3
** File description:
** CPUModule.hpp
*/

#ifndef CPUMODULE_HPP
    #define CPUMODULE_HPP

    #define CPU_NAME_PLACEHOLDER "Unknown"
    #define CPU_FREQ_PLACEHOLDER 3000

    #include "AModule.hpp"

namespace Krell::Modules
{
    class CPUModule final : public AModule
    {
        public:
            explicit CPUModule();
            void update() const override;

        protected:
            static std::string getCPUName();
            static std::uint32_t getFreq();
    };
}
#endif //CPUMODULE_HPP
