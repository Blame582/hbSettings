#include "ScreenSettings.hpp"
#include "../HbSettings.hpp"

std::string ScreenSettings::name() const {
    return "Screen";
}

void ScreenSettings::load(HbSettings &settings) {
    (void)settings;
}

void ScreenSettings::save(HbSettings &settings) const {
    (void)settings;
}
