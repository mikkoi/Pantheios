include_directories(
  ${STLSoft_INCLUDE_DIRS}
)

add_executable( example.cpp.backends.file example.cpp.backends.file.cpp )
target_link_libraries( example.cpp.backends.file
  pantheios.1.core
  pantheios.1.util
  pantheios.1.fe.simple
  pantheios.1.be.file
  pantheios.1.bec.file
  pantheios.1.inserters
)
add_custom_target( examples DEPENDS example.cpp.backends.file )

