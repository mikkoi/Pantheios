include_directories(
  ${STLSoft_INCLUDE_DIRS}
)

add_executable( example.cpp.backends.file.lrsplit example.cpp.backends.file.lrsplit.cpp )
target_link_libraries( example.cpp.backends.file.lrsplit
  pantheios.1.core
  pantheios.1.util
  pantheios.1.fe.simple
  pantheios.1.be.file
  pantheios.1.bec.file
  pantheios.1.inserters
)
add_custom_target( examples DEPENDS example.cpp.backends.file.lrsplit )

