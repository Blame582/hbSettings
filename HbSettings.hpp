#ifndef HBSETTINGS_HPP
#define HBSETTINGS_HPP

#include <map>
#include <string>

class HbSettings {
public:
    bool load(const std::string &path);
    bool save() const;
    bool save(const std::string &path) const;
    std::string get(const std::string &key, const std::string &fallback = "") const;
    void set(const std::string &key, const std::string &value);
    bool contains(const std::string &key) const;

private:
    std::string m_path;
    std::map<std::string, std::string> m_values;
};

#endif
