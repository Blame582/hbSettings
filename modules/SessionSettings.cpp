#include "SessionSettings.hpp"
#include "../HbSettings.hpp"

std::string SessionSettings::name() const {
    return "Session";
}

void SessionSettings::load(HbSettings &settings) {
    (void)settings;
}

void SessionSettings::save(HbSettings &settings) const {
    (void)settings;
}
