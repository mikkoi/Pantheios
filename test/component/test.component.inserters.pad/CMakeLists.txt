include_directories(
  ${STLSoft_INCLUDE_DIRS}
  ${xTests_INCLUDE_DIRS}
)

add_executable( test.component.inserters.pad test.component.inserters.pad.cpp )
target_link_libraries( test.component.inserters.pad
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
add_test( test.component.inserters.pad test.component.inserters.pad )
add_custom_target( tests DEPENDS test.component.inserters.pad )

