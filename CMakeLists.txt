cmake_minimum_required(VERSION 3.20)

project(Lumen LANGUAGES CXX)

# === GLOBAL SETTINGS ===
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# === CONFIGURATIONS ===
set(CMAKE_CONFIGURATION_TYPES "Debug;Release;Dist" CACHE STRING "" FORCE)

# === OUTPUT DIRECTORIES ===
if(WIN32)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
else()
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
endif()

# === PLATFORM MACROS ===
if(WIN32)
    add_compile_definitions(LM_PLATFORM_WINDOWS)
elseif(APPLE)
    add_compile_definitions(LM_PLATFORM_OSX)
elseif(UNIX)
    add_compile_definitions(LM_PLATFORM_LINUX)
endif()

# === CONFIGURATION MACROS ===
# Diese Defines hängen vom Build-Typ ab (Debug / Release / Dist)
add_compile_definitions(
    $<$<CONFIG:Debug>:LM_DEBUG>
    $<$<CONFIG:Release>:LM_RELEASE>
    $<$<CONFIG:Dist>:LM_DIST>
)

# === COMPILER WARNINGS & FLAGS ===
if(MSVC)
    add_compile_options(/W4 /permissive- )
else()
    add_compile_options(-Wall -Wextra -Wpedantic /UTF-8)
endif()

# === SUBDIRECTORIES ===
add_subdirectory(Lumen)
add_subdirectory(Sandbox)

