include_directories(
  ${STLSoft_INCLUDE_DIRS}
  ${xTests_INCLUDE_DIRS}
)

add_executable( test.scratch.fe.simple.WithCallback test.scratch.fe.simple.WithCallback.cpp )
target_link_libraries( test.scratch.fe.simple.WithCallback
  pantheios.1.core
  pantheios.1.util
  pantheios.1.fe.simple.WithCallback
  pantheios.1.be.null
  pantheios.1.bec.null
  pantheios.1.inserters
  xTests::xTests
)
add_test( test.scratch.fe.simple.WithCallback test.scratch.fe.simple.WithCallback )
add_custom_target( tests DEPENDS test.scratch.fe.simple.WithCallback )

