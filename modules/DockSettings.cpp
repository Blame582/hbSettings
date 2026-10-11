#include "DockSettings.hpp"
#include "../HbSettings.hpp"

std::string DockSettings::name() const {
    return "Dock";
}

void DockSettings::load(HbSettings &settings) {
    (void)settings;
}

void DockSettings::save(HbSettings &settings) const {
    (void)settings;
}
