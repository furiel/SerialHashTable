cmake_minimum_required(VERSION 3.5)

project (SerialHashTable VERSION 0.0.1 LANGUAGES C)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake ${PROJECT_SOURCE_DIR}/cmake/)

include(GNUInstallDirs)

find_package(GLIB COMPONENTS gmodule gthread REQUIRED)

add_subdirectory(src)

include(CTest)
if (BUILD_TESTING)
  add_subdirectory(tests)
endif()
