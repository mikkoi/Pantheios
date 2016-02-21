include_directories(
  ${STLSoft_INCLUDE_DIRS}
  ${xTests_INCLUDE_DIRS}
)

add_executable( test.performance.inserters.w2m test.performance.inserters.w2m.cpp )
target_link_libraries( test.performance.inserters.w2m
  pantheios.1.inserters.w2m
  pantheios.1.core
  pantheios.1.util
  pantheios.1.fe.simple
  pantheios.1.be.null
  pantheios.1.bec.null
  xTests::xTests
)
add_test( test.performance.inserters.w2m test.performance.inserters.w2m )
add_custom_target( tests DEPENDS test.performance.inserters.w2m )

