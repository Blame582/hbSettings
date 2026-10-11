
#include "HbSettings.hpp"
#include "SettingsWindow.hpp"

#include "modules/DockSettings.hpp"
#include "modules/ScreenSettings.hpp"
#include "modules/FocusSettings.hpp"
#include "modules/ClockSettings.hpp"
#include "modules/AppearanceSettings.hpp"
#include "modules/SessionSettings.hpp"

#include <Application.hpp>

#include <cstdlib>
#include <iostream>
#include <memory>
#include <string>

int main(int argc, char** argv) {
    const char* home = std::getenv("HOME");
    if (!home) {
        std::cerr << "HOME is not set\n";
        return 1;
    }

    HbSettings settings;
    const std::string config =
        std::string(home) + "/.hackedbox/hackedbox.rc";

    if (!settings.load(config)) {
        std::cerr << "Cannot read " << config << '\n';
        return 1;
    }

    SettingsWindow window(settings);

    window.addModule(std::unique_ptr<SettingsModule>(new DockSettings));
    window.addModule(std::unique_ptr<SettingsModule>(new ScreenSettings));
    window.addModule(std::unique_ptr<SettingsModule>(new FocusSettings));
    window.addModule(std::unique_ptr<SettingsModule>(new ClockSettings));
    window.addModule(std::unique_ptr<SettingsModule>(new AppearanceSettings));
    window.addModule(std::unique_ptr<SettingsModule>(new SessionSettings));
    window.load();

    HbTK::Application app(argc, argv);
    app.addWindow(&window.window());

    return app.exec();
}
