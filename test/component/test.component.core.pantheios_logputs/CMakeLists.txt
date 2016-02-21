include_directories(
  ${STLSoft_INCLUDE_DIRS}
  ${xTests_INCLUDE_DIRS}
)

add_executable( test.component.core.pantheios_logputs test.component.core.pantheios_logputs.cpp )
target_link_libraries( test.component.core.pantheios_logputs
  pantheios.1.fe.simple
  pantheios.1.be.test
  pantheios.1.bec.test
  pantheios.1.core
  pantheios.1.util
  pantheios.1.inserters
  pantheios.1.fe.simple
  pantheios.1.be.test
  pantheios.1.bec.test
  xTests::xTests
)
add_test( test.component.core.pantheios_logputs test.component.core.pantheios_logputs )
add_custom_target( tests DEPENDS test.component.core.pantheios_logputs )

