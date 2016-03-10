include_directories(
  ${STLSoft_INCLUDE_DIRS}
  ${xTests_INCLUDE_DIRS}
)

if (COM)
    add_executable( test.component.inserters.variant_bool test.component.inserters.variant_bool.cpp )
    target_link_libraries( test.component.inserters.variant_bool
      pantheios.1.fe.simple
      pantheios.1.bec.test
      pantheios.1.be.test
      pantheios.1.core
      pantheios.1.util
      pantheios.1.fe.simple
      pantheios.1.bec.test
      pantheios.1.be.test
      pantheios.1.inserters
      xTests::xTests
    )
    add_test( test.component.inserters.variant_bool test.component.inserters.variant_bool )
    add_custom_target( tests DEPENDS test.component.inserters.variant_bool )
endif (COM)

