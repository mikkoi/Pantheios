include_directories(
  ${STLSoft_INCLUDE_DIRS}
  ${xTests_INCLUDE_DIRS}
)

find_package( Threads QUIET)

if( Threads_FOUND )
  add_executable( test.component.be.file.threading test.component.be.file.threading.cpp )
  target_link_libraries( test.component.be.file.threading
    pantheios.1.core
    pantheios.1.util
    pantheios.1.fe.simple
    pantheios.1.be.lrsplit
    pantheios.1.bel.file
    pantheios.1.bec.file
    pantheios.1.ber.fprintf
    pantheios.1.bec.fprintf
    pantheios.1.inserters
    xTests::xTests
    ${CMAKE_THREAD_LIBS_INIT}
  )
  add_test( test.component.be.file.threading test.component.be.file.threading )
  add_custom_target( tests DEPENDS test.component.be.file.threading )
endif( Threads_FOUND )

