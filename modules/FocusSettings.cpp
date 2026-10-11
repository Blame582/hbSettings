#include "FocusSettings.hpp"
#include "../HbSettings.hpp"

std::string FocusSettings::name() const {
    return "Focus";
}

void FocusSettings::load(HbSettings &settings) {
    (void)settings;
}

void FocusSettings::save(HbSettings &settings) const {
    (void)settings;
}
