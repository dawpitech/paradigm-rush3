//
// EPITECH PROJECT, 2025
// Main
// File description:
// Main for rush3
//

#include <thread>

#include "widgetEngine/WidgetEngine.hpp"
#include "widgetEngine/widgets/StringWidget.hpp"

[[noreturn]] void debug_renderer()
{
    const auto widgetEngine = WidgetEngine();
    while (true)
    {
        widgetEngine.refreshData();
        for (const auto& module : *widgetEngine.getModules())
        {
            std::cout << "MODULE " << module->getRenderName() << ":" << std::endl;
            for (const auto& widget : module->getWidgets())
            {
                const auto str_widget = dynamic_cast<Krell::Widgets::StringWidget*>(widget.get());
                std::cout << "\t" << str_widget->getLegend() << " " << str_widget->getValue() << std::endl;
            }
        }
        std::cout << std::endl;
        std::this_thread::sleep_for(std::chrono_literals::operator ""ms(500));
    }
}

int main(const int argc, char **argv, char **env)
{
    if (argc > 1 && (std::string(argv[1]) == "--debug-renderer"))
        debug_renderer();
    return 0;
}
