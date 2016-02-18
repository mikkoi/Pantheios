include_directories (${STLSoft_INCLUDE_DIRS})

add_library( pantheios.1.core
  api.cpp
  api.deprecated.c
  api.exitprocess.cpp
  api.logputs.cpp
  auto.cpp
  logprintf.c
)

# export(TARGETS pantheios.1.core
#   FILE "${CMAKE_BINARY_DIR}/cmake/PantheiosTargets.cmake"
#   NAMESPACE Pantheios::
# )
# install(EXPORT pantheios.1.core
#   FILE PantheiosTargets.cmake
#   NAMESPACE Pantheios::
#   DESTINATION "${CMAKE_BINARY_DIR}/cmake/PantheiosTargets.cmake"
# )

