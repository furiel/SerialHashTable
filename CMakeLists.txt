cmake_minimum_required(VERSION 3.5)

project (SerialHashTable VERSION 0.0.1 LANGUAGES C)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

include(GNUInstallDirs)

find_package(GLIB COMPONENTS gmodule gthread REQUIRED)

add_subdirectory(src)

include(CTest)
if (BUILD_TESTING)
  add_subdirectory(tests)
endif()


include(CMakePackageConfigHelpers)
configure_package_config_file(SerialHashTableConfig.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/SerialHashTableConfig.cmake
  INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/SerialHashTable
)

write_basic_package_version_file (
  "${CMAKE_CURRENT_BINARY_DIR}/SerialHashTableConfigVersion.cmake"
  VERSION ${PROJECT_VERSION}
  COMPATIBILITY SameMajorVersion
)

install(EXPORT serialhashtable-targets
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/SerialHashTable
  NAMESPACE SerialHashTable::
  FILE SerialHashTableTargets.cmake
)

install(FILES
  ${CMAKE_CURRENT_BINARY_DIR}/SerialHashTableConfig.cmake
  ${CMAKE_CURRENT_BINARY_DIR}/SerialHashTableConfigVersion.cmake
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/SerialHashTable
)
