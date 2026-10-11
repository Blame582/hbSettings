# HbSettings

**HbSettings** is a lightweight, modular settings manager for the Hackedbox desktop environment, built with C++ and [HbTK](https://github.com/Blame582/HbTK), the widget toolkit developed for Hackedbox.

It provides a centralized interface for configuring desktop components through independent settings modules, following Hackedbox's focus on simplicity, modularity, and minimal dependencies.

## Features

- **HbTK interface** — Uses the native HbTK widget toolkit.
- **Modular architecture** — Organizes settings into independent, reusable modules.
- **Appearance settings** — Configure desktop appearance options.
- **Clock settings** — Manage clock-related options.
- **Dock settings** — Configure dock behavior.
- **Focus settings** — Adjust window focus behavior.
- **Screen settings** — Manage display-related options.
- **Session settings** — Configure desktop session options.
- **Extensible design** — Add settings modules without redesigning the core application.

## Project Structure

```text
hbSettings/
├── main.cpp
├── HbSettings.cpp
├── HbSettings.hpp
├── SettingsModule.hpp
├── SettingsWindow.cpp
├── SettingsWindow.hpp
└── modules/
    ├── AppearanceSettings.cpp
    ├── AppearanceSettings.hpp
    ├── ClockSettings.cpp
    ├── ClockSettings.hpp
    ├── DockSettings.cpp
    ├── DockSettings.hpp
    ├── FocusSettings.cpp
    ├── FocusSettings.hpp
    ├── ScreenSettings.cpp
    ├── ScreenSettings.hpp
    ├── SessionSettings.cpp
    └── SessionSettings.hpp
```

## Architecture

HbSettings separates the main application from individual settings modules.

- **HbSettings** — Coordinates the application and its settings components.
- **SettingsWindow** — Provides the main settings interface.
- **SettingsModule** — Defines the common interface for settings modules.
- **Modules** — Implement individual desktop configuration categories using HbTK.

This design keeps the application organized and makes it easier to add new configuration categories as Hackedbox develops.

## Dependencies

- **[HbTK](https://github.com/Blame582/HbTK)** — Native widget toolkit for the Hackedbox desktop.
- C++ compiler and the build tools required by HbTK.

## Project Goals

- Provide a native settings utility for Hackedbox.
- Use HbTK for a consistent desktop interface.
- Keep the application lightweight and modular.
- Minimize unnecessary dependencies.
- Make desktop configuration easy to extend and maintain.

## License

See the repository's license information for applicable terms.

## Repository

[Blame582/hbSettings](https://github.com/Blame582/hbSettings)