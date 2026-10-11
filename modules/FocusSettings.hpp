#ifndef FocusSettings_HPP
#define FocusSettings_HPP

#include "../SettingsModule.hpp"
#include <string>

class HbSettings;

class FocusSettings : public SettingsModule {
public:
    std::string name() const override;
    void load(HbSettings &settings) override;
    void save(HbSettings &settings) const override;
};

#endif
