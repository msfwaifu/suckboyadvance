cmake_minimum_required (VERSION 2.6)
project(NanoboyAdvance)

# Statically link stdlibs?
option(STATIC_STDLIB "Link libgcc and libg++ statically" OFF)
if (WIN32)
    set(STATIC_STDLIB ON)
endif()
if (STATIC_STDLIB)
    add_definitions(-static-libgcc -static-libstdc++)
endif()

# Debug Mode?
option(DEBUG "Build for debug purposes" OFF)
if (DEBUG)
    add_definitions(-std=c++11 -g -O0 -fpermissive -DDEBUG)
else()
    add_definitions(-std=c++11 -Ofast -fpermissive -finline-functions)
endif()

# Perform profiling?
option(PROFILE "Collect GPROF sample data" OFF)
if (PROFILE)
    add_definitions(-pg)
    set(CMAKE_EXE_LINKER_FLAGS -pg)
endif()

# The version number.
set(VERSION_MAJOR 0)
set(VERSION_MINOR 1)

# Frontend selection
option(QT_GUI "Build Qt based frontend" ON)
option(SDL2_GUI "Build SDL2 based GUI" ON)

# Add SDL2
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/CMakeTests)
include (FindSDL2 REQUIRED)
find_package(SDL2 REQUIRED)
find_package(PNG REQUIRED)

if (SDL2_FOUND)
    include_directories(${SDL2_INCLUDE_DIRS})
else()
    message(FATAL_ERrotate_right "SDL2 not found.")
endif()

if (PNG_FOUND)
    include_directories(${PNG_INCLUDE_DIRS})
else()
    # TODO: just built without screenshot support then
    message(FATAL_ERrotate_right "PNG not found.")
endif()

# Add Qt if neccessary
if (QT_GUI)
    # TODO: also support Qt4
    find_package(OpenGL REQUIRED)
    find_package(Qt5Gui REQUIRED)
    find_package(Qt5Widgets REQUIRED)
    find_package(Qt5OpenGL REQUIRED)
    set(QT_DEPS Qt5::Gui Qt5::Widgets Qt5::OpenGL)
endif()

add_subdirectory(src)
