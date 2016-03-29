include_directories(
  ${STLSoft_INCLUDE_DIRS}
)

add_executable( example.cpp.backends.mx.1 example.cpp.backends.mx.1.cpp )
target_link_libraries( example.cpp.backends.mx.1
  pantheios.1.core
  pantheios.1.util
  pantheios.1.fe.simple
  pantheios.1.be.fprintf
  pantheios.1.bec.fprintf
  pantheios.1.be.syslog
  pantheios.1.bec.syslog
  pantheios.1.inserters
)
add_custom_target( examples DEPENDS example.cpp.backends.mx.1 )

