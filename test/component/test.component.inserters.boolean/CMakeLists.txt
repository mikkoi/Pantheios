include_directories(
  ${STLSoft_INCLUDE_DIRS}
  ${xTests_INCLUDE_DIRS}
)

add_executable( test.component.inserters.boolean test.component.inserters.boolean.cpp )
target_link_libraries( test.component.inserters.boolean
  pantheios.1.be.test
  pantheios.1.bec.test
  pantheios.1.core
  pantheios.1.util
  pantheios.1.fe.simple
  pantheios.1.be.test
  pantheios.1.bec.test
  pantheios.1.inserters
  xTests::xTests
)
add_test( test.component.inserters.boolean test.component.inserters.boolean )
add_custom_target( tests DEPENDS test.component.inserters.boolean )

