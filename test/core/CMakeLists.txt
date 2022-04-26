file(GLOB_RECURSE SETTINGSBUSCORE_TEST_FILES CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/*.h"
							   "${CMAKE_CURRENT_LIST_DIR}/*.cpp")

if(SETTINGSBUSCORE_TEST_FILES)
  add_executable(SettingsBusCoreTests ${SETTINGSBUSCORE_TEST_FILES})
  target_link_libraries(SettingsBusCoreTests Qt6::Test Qt6::Core Qt6::DBus Qt6::Widgets SettingsBusCore)
  set_target_properties(SettingsBusCoreTests PROPERTIES CXX_STANDARD 20 COMPILE_OPTIONS "${SETTINGSBUS_CXX_FLAGS}")
  target_include_directories(SettingsBusCoreTests PRIVATE ${SETTINGSBUSCORE_SRC_DIR})

  enable_testing()
  add_test(SettingsBusCoreTests SettingsBusCoreTests)
endif()