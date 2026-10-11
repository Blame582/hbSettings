#ifndef DockSettings_HPP
#define DockSettings_HPP

#include "../SettingsModule.hpp"
#include <string>

class HbSettings;

class DockSettings : public SettingsModule {
public:
    std::string name() const override;
    void load(HbSettings &settings) override;
    void save(HbSettings &settings) const override;
};

#endif
