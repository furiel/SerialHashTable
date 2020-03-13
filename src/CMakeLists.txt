add_library(serialhashtable
  SHARED
  serial-hash.c
  serial-list.c)

target_include_directories(serialhashtable
  PUBLIC ${GLIB_INCLUDE_DIRS}
  INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(serialhashtable PUBLIC ${GLIB_LIBRARIES})

install(TARGETS serialhashtable
    EXPORT serialhashtable-export
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})

install(FILES serial-hash.h DESTINATION serial-hash/)
