#pragma once
#include <string>
#include <variant>
#include <vector>
#include <map>
#include <optional>

typedef std::variant<std::string, double, intmax_t, uintmax_t, bool>
    SettingValue;

typedef std::variant<std::vector<SettingValue>,
                     std::map<std::string, SettingValue>,
                     std::optional<SettingValue>>
    Setting;