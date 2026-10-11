#include "ClockSettings.hpp"
#include "../HbSettings.hpp"

std::string ClockSettings::name() const {
    return "Clock";
}

void ClockSettings::load(HbSettings &settings) {
    (void)settings;
}

void ClockSettings::save(HbSettings &settings) const {
    (void)settings;
}
