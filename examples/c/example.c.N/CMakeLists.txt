include_directories(
  ${STLSoft_INCLUDE_DIRS}
)

add_executable( example.c.N example.c.N.c )
target_link_libraries( example.c.N
  pantheios.1.core
  pantheios.1.util
  pantheios.1.fe.simple
  pantheios.1.be.fprintf
  pantheios.1.bec.fprintf
  pantheios.1.be.file
  pantheios.1.bec.file
  pantheios.1.be.null
  pantheios.1.bec.null
  pantheios.1.be.syslog
  pantheios.1.bec.syslog
  pantheios.1.inserters
)
add_custom_target( examples DEPENDS example.c.N )

