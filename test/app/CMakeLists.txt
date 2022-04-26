file(GLOB_RECURSE SETTINGSBUSAPP_TEST_FILES CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/*.h"
							   "${CMAKE_CURRENT_LIST_DIR}/*.cpp")

if(SETTINGSBUSAPP_TEST_FILES)
  add_executable(SettingsBusAppTests ${SETTINGSBUSDAEMON_TEST_FILES})
  target_link_libraries(SettingsBusAppTests Qt6::Test Qt6::Core Qt6::DBus Qt6::Widgets SettingsBusCore)
  set_target_properties(SettingsBusAppTests PROPERTIES CXX_STANDARD 20 COMPILE_OPTIONS "${SETTINGSBUS_CXX_FLAGS}")
  target_include_directories(SettingsBusAppTests PRIVATE ${SETTINGSBUSCORE_SRC_DIR} ${SETTINGSBUSAPP_SRC_DIR})

  enable_testing()
  add_test(SettingsBusAppTests SettingsBusAppTests)
endif()