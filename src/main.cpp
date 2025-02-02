//
// EPITECH PROJECT, 2025
// Main
// File description:
// Main for rush3
//

#include <thread>

#include "app/App.hpp"
#include "displayEngine/sfml/SFMLDisplay.hpp"
#include "widgetEngine/WidgetEngine.hpp"
#include "widgetEngine/widgets/NumericWidget.hpp"
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
                if (dynamic_cast<Krell::Widgets::StringWidget*>(widget.get()) != nullptr)
                {
                    const auto str_widget = dynamic_cast<Krell::Widgets::StringWidget*>(widget.get());
                    std::cout << "\t" << str_widget->getLegend() << " " << str_widget->getValue() << std::endl;
                    continue;
                }
                if (dynamic_cast<Krell::Widgets::NumericWidget*>(widget.get()) != nullptr)
                {
                    const auto str_widget = dynamic_cast<Krell::Widgets::NumericWidget*>(widget.get());
                    std::cout << "\t" << str_widget->getLegend() << " " << str_widget->getValue() << std::endl;
                    continue;
                }
            }
        }
        std::cout << std::endl;
        std::this_thread::sleep_for(std::chrono_literals::operator ""ms(500));
    }
}

int main(const int argc, char **argv)
{
    if (argc > 1 && (std::string(argv[1]) == "--debug-renderer" || std::string(argv[1]) == "-d"))
        debug_renderer();

    auto displayMode = Krell::DisplayType::NCURSES;
    if (argc > 1 && (std::string(argv[1]) == "--SFML" || std::string(argv[1]) == "-s"))
        displayMode = Krell::DisplayType::SFML;

    const Krell::App app(displayMode);
    app.run();
    return 0;
}
