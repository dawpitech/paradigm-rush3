/*
** EPITECH PROJECT, 2025
** paradigm-rush3
** File description:
** SystemModule.hpp
*/

#ifndef SYSTEMMODULE_HPP
    #define SYSTEMMODULE_HPP
    #define OS_RELEASE_PATH "/etc/os-release"
    #define DEFAULT_FIELD_VALUE "Unknown"

    #include "AModule.hpp"

namespace Krell::Modules
{
    class SystemModule final : public AModule
    {
        public:
            explicit SystemModule();
            void update() const override {}

        protected:
            static std::string getOpSys();
            static std::string getKernelVer();
    };
}
#endif //SYSTEMMODULE_HPP
