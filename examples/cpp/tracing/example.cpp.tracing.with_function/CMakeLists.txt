include_directories(
  ${STLSoft_INCLUDE_DIRS}
)

add_executable( example.cpp.tracing.with_function example.cpp.tracing.with_function.cpp )
target_link_libraries( example.cpp.tracing.with_function
  pantheios.1.core
  pantheios.1.util
  pantheios.1.fe.simple
  pantheios.1.be.null
  pantheios.1.bec.null
  pantheios.1.inserters
)
add_custom_target( examples DEPENDS example.cpp.tracing.with_function )

