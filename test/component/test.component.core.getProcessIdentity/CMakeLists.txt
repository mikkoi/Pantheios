include_directories(
  ${STLSoft_INCLUDE_DIRS}
  ${xTests_INCLUDE_DIRS}
)

add_executable( test.component.core.getProcessIdentity test.component.core.getProcessIdentity.c )
target_link_libraries( test.component.core.getProcessIdentity
  pantheios.1.core
  pantheios.1.util
  pantheios.1.fe.simple
  pantheios.1.be.null
  pantheios.1.bec.null
  pantheios.1.inserters
  xTests::xTests
)
add_test( test.component.core.getProcessIdentity test.component.core.getProcessIdentity )
add_custom_target( tests DEPENDS test.component.core.getProcessIdentity )

