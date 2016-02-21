include_directories( ${STLSoft_INCLUDE_DIRS} )

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

