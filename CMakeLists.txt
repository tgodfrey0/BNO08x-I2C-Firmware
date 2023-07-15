cmake_minimum_required(VERSION 3.12)
set(CMAKE_C_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

set(PRJ_NAME "bno08x-firmware")

if(NOT CMAKE_BUILD_TYPE)
  message("Defaulting CMAKE_BUILD_TYPE=Debug")
  set(CMAKE_BUILD_TYPE Debug)
endif()

include(lib/pico-sdk/pico_sdk_init.cmake)

project(${PRJ_NAME})
pico_sdk_init()

add_executable(${PRJ_NAME})
pico_add_extra_outputs(${PRJ_NAME})

target_link_libraries(${PRJ_NAME}
  pico_stdlib
  hardware_i2c
)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  target_compile_definitions(${PRJ_NAME} PRIVATE
    BUILD_DEBUG
  )
endif()

add_subdirectory(src)
add_subdirectory(include)

pico_enable_stdio_usb(${PRJ_NAME} 1)
pico_enable_stdio_uart(${PRJ_NAME} 0)

option(BUILD_DOC "Build documentation" ON)

find_package(Doxygen)
if (DOXYGEN_FOUND)
    # set input and output files
    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile.in)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

    set(CSS1_IN ${CMAKE_CURRENT_SOURCE_DIR}/docs/doxygen-awesome-css/doxygen-awesome.css)
    set(CSS2_IN ${CMAKE_CURRENT_SOURCE_DIR}/docs/doxygen-awesome-css/doxygen-awesome-sidebar-only.css)
    set(CSS3_IN ${CMAKE_CURRENT_SOURCE_DIR}/docs/doxygen-awesome-css/doxygen-awesome-sidebar-only-darkmode-toggle.css)
    set(JS_IN ${CMAKE_CURRENT_SOURCE_DIR}/docs/doxygen-awesome-css/doxygen-awesome-darkmode-toggle.js)
    set(HTML_HEADER_IN ${CMAKE_CURRENT_SOURCE_DIR}/docs/header.html)

    # request to configure the file
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
    message("Doxygen build started")

    file(COPY ${CSS1_IN} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
    file(COPY ${CSS2_IN} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
    file(COPY ${CSS3_IN} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
    file(COPY ${JS_IN} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
    file(COPY ${HTML_IN} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

    # note the option ALL which allows to build the docs together with the application
    add_custom_target( doc_doxygen ALL
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM )
else (DOXYGEN_FOUND)
  message("Doxygen need to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)
