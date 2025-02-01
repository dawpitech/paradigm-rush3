/*
** EPITECH PROJECT, 2025
** paradigm-rush3
** File description:
** WidgetEngine.cpp
*/

#include "WidgetEngine.hpp"
#include "./IModule.hpp"
#include "./IWidget.hpp"
#include "widgetEngine/widgets/HistogramWidget.hpp"
#include "widgetEngine/widgets/ProgressBarWidget.hpp"
#include "widgetEngine/widgets/Widget.hpp"

WidgetEngine::WidgetEngine()
{
    this->_modules = {I};
}
