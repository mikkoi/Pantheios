include_directories(
  ${STLSoft_INCLUDE_DIRS}
)

add_executable( example.c.101 example.c.101.c )
target_link_libraries( example.c.101
  pantheios.1.core
  pantheios.1.util
  pantheios.1.fe.simple
  pantheios.1.be.null
  pantheios.1.bec.null
  pantheios.1.inserters
)
add_custom_target( examples DEPENDS example.c.101 )

