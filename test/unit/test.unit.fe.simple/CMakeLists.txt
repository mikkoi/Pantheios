include_directories(
  ${STLSoft_INCLUDE_DIRS}
  ${xTests_INCLUDE_DIRS}
)

add_executable( test.unit.fe.simple test.unit.fe.simple.c )
target_link_libraries( test.unit.fe.simple
  pantheios.1.core
  pantheios.1.util
  pantheios.1.fe.simple
  xTests::xTests
)
add_test( test.unit.fe.simple test.unit.fe.simple )
add_custom_target( tests DEPENDS test.unit.fe.simple )

