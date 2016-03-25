include_directories(
  ${STLSoft_INCLUDE_DIRS}
  ${xTests_INCLUDE_DIRS}
  ${ZeroMQ_INCLUDE_DIRS}
)

if( ZeroMQ_FOUND )
  add_executable( test.scratch.be.zmq test.scratch.be.zmq.cpp )
  target_link_libraries( test.scratch.be.zmq
    pantheios.1.core
    pantheios.1.util
    pantheios.1.fe.simple
    pantheios.1.be.zmq
    pantheios.1.bec.zmq
    pantheios.1.inserters
    xTests::xTests
  )
  add_test( test.scratch.be.zmq test.scratch.be.zmq )
  add_custom_target( tests DEPENDS test.scratch.be.zmq )
endif( ZeroMQ_FOUND )

