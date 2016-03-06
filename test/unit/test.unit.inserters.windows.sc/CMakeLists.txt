include_directories(
  ${STLSoft_INCLUDE_DIRS}
  ${xTests_INCLUDE_DIRS}
)

if( WIN32 )
  add_executable( test.unit.inserters.windows.sc test.unit.inserters.windows.sc.cpp )
  target_link_libraries( test.unit.inserters.windows.sc
    pantheios.1.core
    pantheios.1.util
    pantheios.1.fe.simple
    pantheios.1.be.null
    pantheios.1.bec.null
    pantheios.1.inserters
    xTests::xTests
  )
  add_test( test.unit.inserters.windows.sc test.unit.inserters.windows.sc )
  add_custom_target( tests DEPENDS test.unit.inserters.windows.sc )
endif( WIN32 )

