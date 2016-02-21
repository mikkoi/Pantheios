include_directories(
  ${STLSoft_INCLUDE_DIRS}
  ${xTests_INCLUDE_DIRS}
)

add_executable( test.unit.util.gethostname test.unit.util.gethostname.cpp )
target_link_libraries( test.unit.util.gethostname
  pantheios.1.core
  pantheios.1.util
  pantheios.1.fe.simple
  pantheios.1.be.null
  pantheios.1.bec.null
  pantheios.1.inserters
  xTests::xTests
)
add_test( test.unit.util.gethostname test.unit.util.gethostname )
add_custom_target( tests DEPENDS test.unit.util.gethostname )

