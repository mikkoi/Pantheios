include_directories(
  ${STLSoft_INCLUDE_DIRS}
  ${xTests_INCLUDE_DIRS}
)

add_executable( test.scratch.be.file test.scratch.be.file.cpp )
target_link_libraries( test.scratch.be.file
  pantheios.1.core
  pantheios.1.util
  pantheios.1.fe.simple
  pantheios.1.be.file
  pantheios.1.bec.file
  pantheios.1.inserters
  xTests::xTests
)
add_test( test.scratch.be.file test.scratch.be.file )
add_custom_target( tests DEPENDS test.scratch.be.file )

