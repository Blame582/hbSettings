#ifndef SETTINGSMODULE_HPP
#define SETTINGSMODULE_HPP

#include <string>

class HbSettings;

class SettingsModule {
public:
    virtual ~SettingsModule() {}
    virtual std::string name() const = 0;
    virtual void load(HbSettings &settings) = 0;
    virtual void save(HbSettings &settings) const = 0;
};

#endif
