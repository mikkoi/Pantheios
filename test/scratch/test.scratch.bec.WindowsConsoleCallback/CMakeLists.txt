include_directories(
  ${STLSoft_INCLUDE_DIRS}
  ${xTests_INCLUDE_DIRS}
)

if (WIN32)
    add_executable( test.scratch.bec.WindowsConsoleCallback test.scratch.bec.WindowsConsoleCallback.cpp )
    target_link_libraries( test.scratch.bec.WindowsConsoleCallback
      pantheios.1.core
      pantheios.1.util
      pantheios.1.fe.simple
      pantheios.1.be.null
      pantheios.1.bec.null
      pantheios.1.inserters
      xTests::xTests
    )
    add_test( test.scratch.bec.WindowsConsoleCallback test.scratch.bec.WindowsConsoleCallback )
    add_custom_target( tests DEPENDS test.scratch.bec.WindowsConsoleCallback )
endif (WIN32)

