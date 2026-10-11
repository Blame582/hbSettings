#ifndef ScreenSettings_HPP
#define ScreenSettings_HPP

#include "../SettingsModule.hpp"
#include <string>

class HbSettings;

class ScreenSettings : public SettingsModule {
public:
    std::string name() const override;
    void load(HbSettings &settings) override;
    void save(HbSettings &settings) const override;
};

#endif
