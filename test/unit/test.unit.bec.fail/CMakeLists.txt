include_directories(
  ${STLSoft_INCLUDE_DIRS}
  ${xTests_INCLUDE_DIRS}
)

add_executable( test.unit.bec.fail test.unit.bec.fail.c )
target_link_libraries( test.unit.bec.fail
  pantheios.1.core
  pantheios.1.util
  pantheios.1.fe.simple
  pantheios.1.be.fail
  pantheios.1.bec.fail
  pantheios.1.inserters
  xTests::xTests
)
add_test( test.unit.bec.fail test.unit.bec.fail )
add_custom_target( tests DEPENDS test.unit.bec.fail )

