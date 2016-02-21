include_directories(
  ${STLSoft_INCLUDE_DIRS}
  ${xTests_INCLUDE_DIRS}
)

add_executable( test.component.inserters.args test.component.inserters.args.cpp )
target_link_libraries( test.component.inserters.args
  pantheios.1.be.test
  pantheios.1.bec.test
  pantheios.1.inserters
  pantheios.1.core
  pantheios.1.util
  pantheios.1.fe.simple
  pantheios.1.be.test
  pantheios.1.bec.test
  pantheios.1.inserters
  xTests::xTests
)
add_test( test.component.inserters.args test.component.inserters.args )
add_custom_target( tests DEPENDS test.component.inserters.args )

