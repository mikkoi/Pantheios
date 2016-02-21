if( WIN32 )
include_directories(
  ${STLSoft_INCLUDE_DIRS}
  ${xTests_INCLUDE_DIRS}
)

add_executable( test.unit.bec.COMErrorObject test.unit.bec.COMErrorObject.cpp )
target_link_libraries( test.unit.bec.COMErrorObject
  pantheios.1.core
  pantheios.1.util
  pantheios.1.fe.simple
  pantheios.1.be.null
  pantheios.1.bec.null
  pantheios.1.inserters
  xTests::xTests
)
add_test( test.unit.bec.COMErrorObject test.unit.bec.COMErrorObject )
add_custom_target( tests DEPENDS test.unit.bec.COMErrorObject )
endif( WIN32 )

