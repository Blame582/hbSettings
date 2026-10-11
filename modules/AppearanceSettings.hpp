#ifndef AppearanceSettings_HPP
#define AppearanceSettings_HPP

#include "../SettingsModule.hpp"
#include <string>

class HbSettings;

class AppearanceSettings : public SettingsModule {
public:
    std::string name() const override;
    void load(HbSettings &settings) override;
    void save(HbSettings &settings) const override;
};

#endif
