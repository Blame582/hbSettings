#include "HbSettings.hpp"

#include <fstream>

bool HbSettings::load(const std::string &path) {
    std::ifstream file(path.c_str());
    if (!file)
        return false;

    m_path = path;
    m_values.clear();

    std::string line;
    while (std::getline(file, line)) {
        std::string::size_type pos = line.find(':');
        if (pos == std::string::npos)
            continue;

        std::string key = line.substr(0, pos);
        std::string value = line.substr(pos + 1);

        while (!key.empty() && (key.back() == ' ' || key.back() == '\t'))
            key.pop_back();
        while (!value.empty() && (value.front() == ' ' || value.front() == '\t'))
            value.erase(0, 1);

        if (!key.empty())
            m_values[key] = value;
    }

    return true;
}

bool HbSettings::save() const {
    return save(m_path);
}

bool HbSettings::save(const std::string &path) const {
    std::ofstream file(path.c_str());
    if (!file)
        return false;

    for (std::map<std::string, std::string>::const_iterator it = m_values.begin();
         it != m_values.end(); ++it)
        file << it->first << ":\t" << it->second << '\n';

    return file.good();
}

std::string HbSettings::get(const std::string &key, const std::string &fallback) const {
    std::map<std::string, std::string>::const_iterator it = m_values.find(key);
    return it == m_values.end() ? fallback : it->second;
}

void HbSettings::set(const std::string &key, const std::string &value) {
    m_values[key] = value;
}

bool HbSettings::contains(const std::string &key) const {
    return m_values.find(key) != m_values.end();
}
