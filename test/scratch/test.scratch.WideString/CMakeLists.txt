include_directories(
  ${STLSoft_INCLUDE_DIRS}
  ${xTests_INCLUDE_DIRS}
)

add_executable( test.scratch.WideString test.scratch.WideString.cpp )
target_link_libraries( test.scratch.WideString
  pantheios.1.core
  pantheios.1.util
  pantheios.1.fe.simple
  pantheios.1.be.null
  pantheios.1.bec.null
  pantheios.1.inserters
  xTests::xTests
)
add_test( test.scratch.WideString test.scratch.WideString )
add_custom_target( tests DEPENDS test.scratch.WideString )

