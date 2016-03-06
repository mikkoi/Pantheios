include_directories(
  ${STLSoft_INCLUDE_DIRS}
  ${xTests_INCLUDE_DIRS}
)

add_executable( test.unit.getversion test.unit.getversion.c )
set_target_properties( test.unit.getversion
  PROPERTIES COMPILE_DEFINITIONS PANTHEIOS_FE_PROCESS_IDENTITY=test.unit.getversion.identity )
target_link_libraries( test.unit.getversion
  pantheios.1.core
  pantheios.1.util
  pantheios.1.fe.simple
  pantheios.1.be.null
  pantheios.1.bec.null
  pantheios.1.inserters
  xTests::xTests
)
add_test( test.unit.getversion test.unit.getversion )
add_custom_target( tests DEPENDS test.unit.getversion )

