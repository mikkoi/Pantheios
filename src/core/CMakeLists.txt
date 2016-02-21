include_directories (${STLSoft_INCLUDE_DIRS})

add_library( pantheios.1.core
  api.cpp
  api.deprecated.c
  api.exitprocess.cpp
  api.logputs.cpp
  auto.cpp
  logprintf.c
)

