include_directories(
  ${STLSoft_INCLUDE_DIRS}
)

add_executable( example.c.util.gethostname example.c.util.gethostname.c )
target_link_libraries( example.c.util.gethostname
  pantheios.1.core
  pantheios.1.util
  pantheios.1.fe.simple
  pantheios.1.be.null
  pantheios.1.bec.null
  pantheios.1.inserters
)
add_custom_target( examples DEPENDS example.c.util.gethostname )

