
file(GLOB_RECURSE SETTINGSBUSAPP_FILES CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/*.cpp" 
    "${CMAKE_CURRENT_LIST_DIR}/*.h" 
    "${CMAKE_CURRENT_LIST_DIR}/*.ui")
add_executable(SettingsBus ${SETTINGSBUSAPP_FILES})
target_link_libraries(SettingsBus PRIVATE Qt6::Widgets Qt6::Core Qt6::DBus SettingsBusCore)
set_target_properties(SettingsBus PROPERTIES CXX_STANDARD 20 COMPILE_OPTIONS "${SETTINGSBUS_CXX_FLAGS}")
target_include_directories(SettingsBus PRIVATE ${SETTINGSBUSCORE_SRC_DIR})