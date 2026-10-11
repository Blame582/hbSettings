
#include "SettingsWindow.hpp"

#include <Painter.hpp>
#include <Colors.hpp>
#include <Widget.hpp>

#include <string>
#include <vector>

namespace {
const int SidebarWidth = 190;
const int HeaderHeight = 54;
const int FooterHeight = 58;
const int ItemHeight = 38;

const HbTK::Colors Background("#252525");
const HbTK::Colors Sidebar("#202020");
const HbTK::Colors Selected("#414b5b");
const HbTK::Colors Border("#454545");
const HbTK::Colors Text("#e0e0e0");
const HbTK::Colors Muted("#a0a0a0");
}

class SettingsCanvas : public HbTK::Widget {
public:
    explicit SettingsCanvas(SettingsWindow& owner)
        : m_owner(owner), m_page(0) {
        m_pages = {
            "Dock",
            "Screen / Workspaces",
            "Focus / Input",
            "Clock",
            "Appearance",
            "Session / Files"
        };
    }

    void paint(HbTK::Painter& p) override {
        p.fillRect(0, 0, width(), height(), Background);
        p.fillRect(0, 0, SidebarWidth, height(), Sidebar);
        p.fillRect(0, 0, SidebarWidth, HeaderHeight,
                   HbTK::Colors("#191919"));
        p.drawText(20, 33, "HbSetting", Text);

        int y = HeaderHeight + 12;
        for (std::size_t i = 0; i < m_pages.size(); ++i) {
            if (static_cast<int>(i) == m_page)
                p.fillRect(8, y, SidebarWidth - 16,
                           ItemHeight, Selected);

            p.drawText(20, y + 24, m_pages[i].c_str(),
                       static_cast<int>(i) == m_page ? Text : Muted);
            y += ItemHeight + 4;
        }

        p.fillRect(SidebarWidth, 0, 1, height(), Border);
        p.drawText(SidebarWidth + 28, 34,
                   m_pages[m_page].c_str(), Text);

        p.fillRect(SidebarWidth + 24, HeaderHeight,
                   width() - SidebarWidth - 48, 1, Border);

        drawPage(p);

        p.fillRect(SidebarWidth, height() - FooterHeight,
                   width() - SidebarWidth, 1, Border);

        drawButton(p, width() - 300, "Cancel", false);
        drawButton(p, width() - 210, "Apply", false);
        drawButton(p, width() - 120, "Save", true);
    }

    void mousePress(int x, int y, unsigned int button) override {
        if (button != 1)
            return;

        if (x < SidebarWidth && y >= HeaderHeight) {
            int item = (y - HeaderHeight - 12) / (ItemHeight + 4);
            if (item >= 0 && item < static_cast<int>(m_pages.size())) {
                m_page = item;
                return;
            }
        }

        if (y >= height() - FooterHeight) {
            if (x >= width() - 120 && x < width() - 24)
                m_owner.save();
        }
    }

private:
    void drawButton(HbTK::Painter& p, int x,
                    const char* label, bool primary) {
        const int y = height() - 43;
        if (primary)
            p.fillRect(x, y, 88, 30, Selected);
        else
            p.drawRect(x, y, 78, 30, Border);

        p.drawText(x + 15, y + 20, label, Text);
    }

    void drawField(HbTK::Painter& p, int x, int y,
                   const char* label, const char* value) {
        p.drawText(x, y, label, Muted);
        p.drawRect(width() - 270, y - 21, 210, 30, Border);
        p.drawText(width() - 258, y - 2, value, Text);
    }

    void drawCheck(HbTK::Painter& p, int x, int y,
                   const char* label, bool checked) {
        p.drawRect(x, y - 17, 16, 16, Border);
        if (checked)
            p.drawText(x + 3, y - 4, "x", Text);
        p.drawText(x + 28, y - 4, label, Muted);
    }

    void drawPage(HbTK::Painter& p) {
        const int x = SidebarWidth + 28;
        int y = HeaderHeight + 36;

        switch (m_page) {
        case 0:
            drawCheck(p, x, y += 12, "Enable dock", false);
            drawField(p, x, y += 46, "Position", "top");
            drawField(p, x, y += 42, "Edge alignment", "center");
            drawField(p, x, y += 42, "Dock size", "600");
            break;

        case 1:
            drawField(p, x, y, "Workspace count", "1");
            drawField(p, x, y += 42, "Workspace names", "Workspace 1");
            drawField(p, x, y += 42, "Window placement", "RowSmartPlacement");
            drawField(p, x, y += 42, "Row direction", "LeftToRight");
            drawField(p, x, y += 42, "Column direction", "TopToBottom");
            drawField(p, x, y += 42, "Edge snap threshold", "0");
            break;

        case 2:
            drawField(p, x, y, "Focus model", "ClickToFocus");
            drawCheck(p, x, y += 42, "Focus new windows", true);
            drawCheck(p, x, y += 38, "Focus last window", false);
            drawCheck(p, x, y += 38, "Full maximization", false);
            drawField(p, x, y += 42, "Auto-raise delay", "400");
            drawField(p, x, y += 42, "Double-click interval", "250");
            break;

        case 3:
            drawCheck(p, x, y += 12, "Enable clock", true);
            drawField(p, x, y += 42, "Date format", "%m/%d/%Y");
            drawField(p, x, y += 42, "Time format", "%I:%M:%S %p");
            drawField(p, x, y += 42, "Target", "menu");
            drawField(p, x, y += 42, "Color", "#00FF00");
            drawField(p, x, y += 42, "Horizontal position", "20");
            drawField(p, x, y += 42, "Vertical position", "20");
            break;

        case 4:
            drawField(p, x, y, "Style file", "~/.hackedbox/styles/default");
            drawCheck(p, x, y += 42, "Image dithering", true);
            drawField(p, x, y += 42, "Colors per channel", "4");
            break;

        case 5:
            drawField(p, x, y, "Menu file", "~/.hackedbox/menu");
            drawCheck(p, x, y += 42, "Opaque window movement", false);
            drawField(p, x, y += 42, "Cache lifetime", "5");
            drawField(p, x, y += 42, "Cache maximum", "200");
            drawCheck(p, x, y += 42, "Key bindings", true);
            break;
        }
    }

    SettingsWindow& m_owner;
    std::vector<std::string> m_pages;
    int m_page;
};

SettingsWindow::SettingsWindow(HbSettings& settings)
    : m_settings(settings),
      m_window(100, 100, 850, 600),
      m_canvas(new SettingsCanvas(*this)) {
    m_window.setTitle("HbSetting");
    m_window.setCentralWidget(m_canvas.get());
}

SettingsWindow::~SettingsWindow() = default;

void SettingsWindow::addModule(
    std::unique_ptr<SettingsModule> module) {
    if (module)
        m_modules.push_back(std::move(module));
}

void SettingsWindow::load() {
    for (auto& module : m_modules)
        module->load(m_settings);
}

void SettingsWindow::save() {
    for (const auto& module : m_modules)
        module->save(m_settings);

    m_settings.save();
}

HbTK::Window& SettingsWindow::window() {
    return m_window;
}
