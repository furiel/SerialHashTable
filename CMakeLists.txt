cmake_minimum_required(VERSION 3.5)

project (SerialHashTable C)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake ${PROJECT_SOURCE_DIR}/cmake/)

include(GNUInstallDirs)

find_package(GLIB COMPONENTS gmodule gthread REQUIRED)

add_subdirectory(src)

option(BUILD_TESTING "Build tests" "ON")
if (BUILD_TESTING)
enable_testing()
add_subdirectory(tests)
endif()
