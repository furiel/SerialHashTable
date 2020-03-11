include(LibFindMacros)

libfind_pkg_check_modules(CRITERION_PKGCONF criterion)

libfind_pkg_detect(CRITERION criterion FIND_PATH criterion/criterion.h FIND_LIBRARY criterion)
set(CRITERION_PROCESS_INCLUDES CRITERION_INCLUDE_DIR)
set(CRITERION_PROCESS_LIBS CRITERION_LIBRARY)
libfind_process(CRITERION)

if (NOT CRITERION_FOUND)
    MESSAGE(WARNING "Criterion not found: some unit tests will not be compiled")
endif()
