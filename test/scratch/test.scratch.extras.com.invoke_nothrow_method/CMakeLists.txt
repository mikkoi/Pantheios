include_directories(
  ${STLSoft_INCLUDE_DIRS}
  ${Pantheios.Extras_INCLUDE_DIRS}
  ${xTests_INCLUDE_DIRS}
)

if( Pantheios.Extras_FOUND )
  add_executable( test.scratch.extras.com.invoke_nothrow_method test.scratch.extras.com.invoke_nothrow_method.cpp )
  target_link_libraries( test.scratch.extras.com.invoke_nothrow_method
    pantheios.1.core
    pantheios.1.util
    pantheios.1.fe.simple
    pantheios.1.be.null
    pantheios.1.bec.null
    pantheios.1.inserters
    xTests::xTests
  )
  add_test( test.scratch.extras.com.invoke_nothrow_method test.scratch.extras.com.invoke_nothrow_method )
  add_custom_target( tests DEPENDS test.scratch.extras.com.invoke_nothrow_method )
endif( Pantheios.Extras_FOUND )

