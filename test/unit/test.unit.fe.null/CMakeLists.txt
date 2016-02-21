include_directories(
  ${STLSoft_INCLUDE_DIRS}
  ${xTests_INCLUDE_DIRS}
)

add_executable( test.unit.fe.null test.unit.fe.null.c )
target_link_libraries( test.unit.fe.null
  pantheios.1.core
  pantheios.1.util
  pantheios.1.fe.simple
  pantheios.1.be.null
  pantheios.1.bec.null
  pantheios.1.inserters
  xTests::xTests
)
add_test( test.unit.fe.null test.unit.fe.null )
add_custom_target( tests DEPENDS test.unit.fe.null )

