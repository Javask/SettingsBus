cmake_minimum_required(VERSION 3.10 FATAL_ERROR)


file(GLOB_RECURSE SETTINGSBUS_TEST_FILES CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/*.h"
							   "${CMAKE_CURRENT_LIST_DIR}/*.cpp")


add_executable(SettingsBusTests ${SETTINGSBUS_TEST_FILES})
target_link_libraries(SettingsBusTests Qt6::Test Qt6::Core Qt6::DBus Qt6::Widgets SettingsBusCore)
set_target_properties(SettingsBusTests PROPERTIES CXX_STANDARD 20 COMPILE_OPTIONS "${SETTINGSBUS_CXX_FLAGS}")
target_include_directories(SettingsBusTests PRIVATE ${SETTINGSBUSCORE_SRC_DIR})

enable_testing()
add_test(SettingsBusTests SettingsBusTests)