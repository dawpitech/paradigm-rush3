/*
** EPITECH PROJECT, 2025
** paradigm-rush3
** File description:
** Exceptions.hpp
*/

#ifndef EXCEPTIONS_HPP
    #define EXCEPTIONS_HPP
#include <exception>
#include <string>

namespace Krell::Widgets::Exceptions
{
    class GenericWidgetException : public std::exception
    {
        public:
            explicit GenericWidgetException(const std::string& what) { this->_what = what; }
            [[nodiscard]] const char* what() const noexcept override { return this->_what.c_str(); }

        protected:
            std::string _what;
    };
    class NoSystemAccess final : public GenericWidgetException
    {
        public:
            explicit NoSystemAccess(): GenericWidgetException("Couldn't access system data") {}
    };
    class NoKernelInfoAccess final : public GenericWidgetException
    {
    public:
        explicit NoKernelInfoAccess(): GenericWidgetException("Couldn't access kernel infos") {}
    };
}
#endif //EXCEPTIONS_HPP
