#ifndef SessionSettings_HPP
#define SessionSettings_HPP

#include "../SettingsModule.hpp"
#include <string>

class HbSettings;

class SessionSettings : public SettingsModule {
public:
    std::string name() const override;
    void load(HbSettings &settings) override;
    void save(HbSettings &settings) const override;
};

#endif
