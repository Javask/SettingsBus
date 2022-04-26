cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

project(SettingsBus VERSION 1.0.0 LANGUAGES CXX)


if(MSVC)
  set(SETTINGSBUS_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Wall /EHsc")
else()
  set(SETTINGSBUS_CXX_FLAGS ${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic)
endif()

option(SETTINGSBUS_BUILD_DAEMON "Build daemon" ON)
option(SETTINGSBUS_BUILD_APP "Build gui application" ON)
option(SETTINGSBUS_BUILD_TESTS "Build test executables" ON)

set(QT_COMPONENTS Core DBus)
if(${SETTINGSBUS_BUILD_APP})
  list(APPEND QT_COMPONENTS Widgets)
endif()

if(${SETTINGSBUS_BUILD_TESTS})
  list(APPEND QT_COMPONENTS Test)
endif()

find_package(Qt6 REQUIRED COMPONENTS ${QT_COMPONENTS})

qt_standard_project_setup()

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/src)


if(${SETTINGSBUS_BUILD_TESTS})
  add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/test/")
endif()