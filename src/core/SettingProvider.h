#pragma once
#include <cstddef>
#include <string>
#include "Setting.h"

class SettingProvider {
 protected:
  SettingProvider() = default;

 public:
  virtual ~SettingProvider() = default;
  virtual size_t getSettingsCount() const = 0;
  virtual void setSetting(const std::string& key, const Setting& value) = 0;
  virtual Setting getSetting(const std::string& key) = 0;
};