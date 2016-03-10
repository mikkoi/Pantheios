include_directories(
  ${STLSoft_INCLUDE_DIRS}
  ${xTests_INCLUDE_DIRS}
)

add_executable( test.scratch.be.N.fail test.scratch.be.N.fail.cpp )
target_link_libraries( test.scratch.be.N.fail
  pantheios.1.core
  pantheios.1.util
  pantheios.1.fe.simple
  pantheios.1.be.N
  pantheios.1.bec.fail
  pantheios.1.bec.file
  pantheios.1.bec.fprintf
  pantheios.1.inserters
  xTests::xTests
)
add_test( test.scratch.be.N.fail test.scratch.be.N.fail )
add_custom_target( tests DEPENDS test.scratch.be.N.fail )

