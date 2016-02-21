include_directories(
  ${STLSoft_INCLUDE_DIRS}
  ${xTests_INCLUDE_DIRS}
)

add_executable( test.performance.inserters.m2w test.performance.inserters.m2w.cpp )
target_link_libraries( test.performance.inserters.m2w
  pantheios.1.inserters.m2w
  pantheios.1.core
  pantheios.1.util
  pantheios.1.fe.simple
  pantheios.1.be.null
  pantheios.1.bec.null
  xTests::xTests
)
add_test( test.performance.inserters.m2w test.performance.inserters.m2w )
add_custom_target( tests DEPENDS test.performance.inserters.m2w )

