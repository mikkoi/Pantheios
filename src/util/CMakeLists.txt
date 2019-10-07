add_library( pantheios.1.util
  bailout.c
  core.apidefs.cpp
  processid.c
  strdup.c
  time.cpp
  be.context.cpp
  hostname.c
  severity_strings.c
  strnlen.cpp
  util.strnlen.c
  be.parse.cpp
  init_code_strings.c
  snprintf.c
  threadid.c
)
target_link_libraries(pantheios.1.util STLSoft::STLSoft)
target_include_directories( pantheios.1.util PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)
install(TARGETS
    pantheios.1.util
    EXPORT project-targets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

