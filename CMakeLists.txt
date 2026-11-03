cmake_minimum_required(VERSION 3.25) 

project(linux-camera-definitive)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}")

message("Compiling wxwidgets...")

# initialize the variables inside the wxwidgets file

# default should be static library, but not monolithic since it will cause intense bloats

set(wxBUILD_DEBUG_LEVEL 0 CACHE STRING "DEBUG LEVEL")

set(wxBUILD_DEBUG_LEVEL 1 CACHE STRING "DEBUG LEVEL" FORCE)


# set(wxBUILD_MONOLITH)

option(wxBUILD_SHARED "" OFF)

option(wxBUILD_INSTALL "" OFF)

option(wxBUILD_STRIPPED_RELEASE "" ON)

option(wxBUILD_OPTIMISE ON)

#option(wxBUILD_USE_STATIC_RUNTIME)

#set(wxBUILD_MONOLITHIC ON)

add_subdirectory(wxWidgets)

#use find package now

#set hints for find_package

option(wxWidgets_USE_STATIC "" OFF)

#set(wxWidgets_CONFIG_EXECUTABLE CACHE STRING "${PROJECT_BINARY_DIR}/wxWidgets/lib/wx/config/gtk3-unicode-static-3.3")

set(wxWidgets_CHECK_LIBRARIES OFF CACHE BOOL "" FORCE) # Not checking libraries yet because stuffs is not built yet 

find_package(CustomWxWidgets COMPONENTS base core net)

if(NOT wxWidgets_FOUND)
  message(FATAL_ERROR "wxwidgets build not found (any build at all). A lot of stuffs to fix, LOL")
endif()

add_executable(LinuxCameraDefinitive)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp")

target_sources(LinuxCameraDefinitive PRIVATE ${SOURCES})

#file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS "include/*.cpp")

target_include_directories(LinuxCameraDefinitive PUBLIC ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(LinuxCameraDefinitive PRIVATE wxWidgets::wxWidgets)





