add_library(serialhashtable
  SHARED
  serial-hash.c
  serial-list.c)

target_include_directories(serialhashtable
  PUBLIC ${GLIB_INCLUDE_DIRS}
  INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/serial-hash>
)

set_target_properties(serialhashtable PROPERTIES
  PUBLIC_HEADER serial-hash.h
)

target_link_libraries(serialhashtable PUBLIC ${GLIB_LIBRARIES})

install(TARGETS serialhashtable
  EXPORT serialhashtable-targets
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/serial-hash
  INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)
