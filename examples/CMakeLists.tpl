include_directories(
  ${STLSoft_INCLUDE_DIRS}
)

add_executable( FILE FILE.cpp )
target_link_libraries( FILE
  pantheios.1.core
  pantheios.1.util
  pantheios.1.fe.simple
  pantheios.1.be.null
  pantheios.1.bec.null
  pantheios.1.inserters
)
add_custom_target( examples DEPENDS FILE )

