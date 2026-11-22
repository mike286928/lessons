cmake_minimum_required(VERSION 3.20)
project(sort_cmake LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_SUPPRESS_REGENERATION true)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

if(APPLE)
    set(CMAKE_BUILD_WITH_INSTALL_RPATH true)
    set(CMAKE_INSTALL_RPATH "@loader_path")
endif()

set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
add_subdirectory(../lib/googletest "${CMAKE_BINARY_DIR}/googletest")

set(SORT_LIB sort)
enable_testing()
add_subdirectory(sort)
add_subdirectory(test)

set(SOURCES
    main.cpp
)

add_executable(main ${SOURCES})

target_link_libraries(main
    ${SORT_LIB}
)
