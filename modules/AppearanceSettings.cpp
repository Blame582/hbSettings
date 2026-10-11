#include "AppearanceSettings.hpp"
#include "../HbSettings.hpp"

std::string AppearanceSettings::name() const {
    return "Appearance";
}

void AppearanceSettings::load(HbSettings &settings) {
    (void)settings;
}

void AppearanceSettings::save(HbSettings &settings) const {
    (void)settings;
}
