include_directories(
  ${STLSoft_INCLUDE_DIRS}
  ${xTests_INCLUDE_DIRS}
)

if( 0 )
  add_executable( test.unit.inserter.w2m test.unit.inserter.w2m.cpp )
  target_link_libraries( test.unit.inserter.w2m
    pantheios.1.core
    pantheios.1.util
    pantheios.1.fe.simple
    pantheios.1.be.null
    pantheios.1.bec.null
    pantheios.1.inserters.w2m
    xTests::xTests
  )
  add_test( test.unit.inserter.w2m test.unit.inserter.w2m )
  add_custom_target( tests DEPENDS test.unit.inserter.w2m )
endif( 0 )

