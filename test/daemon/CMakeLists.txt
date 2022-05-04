file(GLOB_RECURSE SETTINGSBUSDAEMON_TEST_FILES CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/*.h"
							   "${CMAKE_CURRENT_LIST_DIR}/*.cpp")

if(SETTINGSBUSDAEMON_TEST_FILES)
  add_executable(SettingsBusDaemonTests ${SETTINGSBUSDAEMON_TEST_FILES})
  target_link_libraries(SettingsBusDaemonTests Qt6::Test Qt6::Core Qt6::DBus Qt6::Widgets SettingsBusCore)
  set_target_properties(SettingsBusDaemonTests PROPERTIES CXX_STANDARD 20 COMPILE_OPTIONS "${SETTINGSBUS_CXX_FLAGS}")
  target_include_directories(SettingsBusDaemonTests PRIVATE ${SETTINGSBUSCORE_SRC_DIR} ${SETTINGSBUSDAEMON_SRC_DIR})

  add_test(SettingsBusDaemonTests ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/SettingsBusDaemonTests)
  set_tests_properties(SettingsBusDaemonTests PROPERTIES ENVIRONMENT ${TEST_ENVIRONMENT_VARS})
endif()