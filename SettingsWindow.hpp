
#pragma once

#include "HbSettings.hpp"
#include "SettingsModule.hpp"

#include <MainWindow.hpp>
#include <memory>
#include <vector>

namespace HbTK {
class StyleEngine;
}

class SettingsCanvas;

class SettingsWindow {
public:
    explicit SettingsWindow(HbSettings& settings);
    ~SettingsWindow();

    void addModule(std::unique_ptr<SettingsModule> module);
    void load();
    void save();

    HbTK::Window& window();

private:
    HbSettings& m_settings;
    HbTK::Window m_window;
    std::unique_ptr<SettingsCanvas> m_canvas;
    std::vector<std::unique_ptr<SettingsModule>> m_modules;
};
