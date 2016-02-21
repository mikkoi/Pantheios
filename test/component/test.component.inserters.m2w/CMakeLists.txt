include_directories(
  ${STLSoft_INCLUDE_DIRS}
  ${xTests_INCLUDE_DIRS}
)

if( PANTHEIOS_USE_WIDE_STRINGS )
add_executable( test.component.inserters.m2w test.component.inserters.m2w.cpp )
target_link_libraries( test.component.inserters.m2w
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
add_test( test.component.inserters.m2w test.component.inserters.m2w )
add_custom_target( tests DEPENDS test.component.inserters.m2w )
endif( PANTHEIOS_USE_WIDE_STRINGS )

