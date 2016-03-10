include_directories(
  ${STLSoft_INCLUDE_DIRS}
  ${b64_INCLUDE_DIRS}
  ${xTests_INCLUDE_DIRS}
)

if( WIN32 )
  add_executable( test.scratch.WideString test.scratch.WideString.cpp )
  target_link_libraries( test.scratch.WideString
    pantheios.1.core
    pantheios.1.util
    pantheios.1.fe.simple
    pantheios.1.be.null
    pantheios.1.bec.null
    pantheios.1.inserters.w2m
    b64::b64
    xTests::xTests
  )
  add_test( test.scratch.WideString test.scratch.WideString )
  add_custom_target( tests DEPENDS test.scratch.WideString )
endif( WIN32 )

