#ifndef ClockSettings_HPP
#define ClockSettings_HPP

#include "../SettingsModule.hpp"
#include <string>

class HbSettings;

class ClockSettings : public SettingsModule {
public:
    std::string name() const override;
    void load(HbSettings &settings) override;
    void save(HbSettings &settings) const override;
};

#endif
