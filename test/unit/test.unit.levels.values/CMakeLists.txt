include_directories(
  ${STLSoft_INCLUDE_DIRS}
  ${xTests_INCLUDE_DIRS}
)

add_executable( test.unit.levels.values test.unit.levels.values.c )
target_link_libraries( test.unit.levels.values
  pantheios.1.core
  pantheios.1.util
  pantheios.1.fe.simple
  pantheios.1.be.null
  pantheios.1.bec.null
  pantheios.1.inserters
  xTests::xTests
)
add_test( test.unit.levels.values test.unit.levels.values )
add_custom_target( tests DEPENDS test.unit.levels.values )

