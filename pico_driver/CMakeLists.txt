# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)

# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.2.0)
set(toolchainVersion 14_2_Rel1)
set(picotoolVersion 2.2.0-a4)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(Main C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1

add_subdirectory(Shared)

add_executable(Main
    main.cpp
)

# ====================================================================================
set(PICO_BOARD pico_w CACHE STRING "Board type")
if(PICO_BOARD STREQUAL "pico_w")
    # target_sources(${PROJECT_NAME} PRIVATE bluetooth.cpp)
    message(STATUS "Building Bluetooth module for Pico W")
    target_compile_definitions(Main PRIVATE ENABLE_BLUETOOTH)
endif()
# ====================================================================================

include_directories(
    ${CMAKE_CURRENT_LIST_DIR}/Shared/includes
)

pico_set_program_name(Main "Main")
pico_set_program_version(Main "0.1")

# Modify the below lines to enable/disable output over UART/USB
pico_enable_stdio_uart(Main 1)
pico_enable_stdio_usb(Main 1)

# Add the standard library to the build
target_link_libraries(
    Main
    PRIVATE
    Shared
    pico_stdlib
)

if(PICO_BOARD STREQUAL "pico_w")
    target_link_libraries(Main PRIVATE pico_cyw43_arch_none)
endif()

# Add the standard include files to the build
target_include_directories(Main PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
    ${CMAKE_CURRENT_LIST_DIR}/Shared/includes
)

pico_add_extra_outputs(Main)

