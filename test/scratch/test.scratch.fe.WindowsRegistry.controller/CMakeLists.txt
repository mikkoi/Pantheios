if( WIN32 )
include_directories(
  ${STLSoft_INCLUDE_DIRS}
  ${xTests_INCLUDE_DIRS}
)

add_executable( test.scratch.fe.WindowsRegistry.controller test.scratch.fe.WindowsRegistry.controller.cpp )
target_link_libraries( test.scratch.fe.WindowsRegistry.controller
  pantheios.1.core
  pantheios.1.util
  pantheios.1.fe.simple
  pantheios.1.be.null
  pantheios.1.bec.null
  pantheios.1.inserters
  xTests::xTests
)
add_test( test.scratch.fe.WindowsRegistry.controller test.scratch.fe.WindowsRegistry.controller )
add_custom_target( tests DEPENDS test.scratch.fe.WindowsRegistry.controller )
endif( WIN32 )

