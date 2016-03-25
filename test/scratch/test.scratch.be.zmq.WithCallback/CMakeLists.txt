include_directories(
  ${STLSoft_INCLUDE_DIRS}
  ${xTests_INCLUDE_DIRS}
  ${ZeroMQ_INCLUDE_DIRS}
)

if( ZeroMQ_FOUND )
  add_executable( test.scratch.be.zmq.WithCallback test.scratch.be.zmq.WithCallback.cpp )
  set_source_files_properties( test.scratch.be.zmq.WithCallback.cpp
    PROPERTIES
      COMPILE_DEFINITIONS PANTHEIOS_BE_USE_CALLBACK=1
      COMPILE_FLAGS -std=c++11
  )
  # set_target_properties( test.scratch.be.zmq.WithCallback PROPERTIES CXX_STANDARD 11)
  target_link_libraries( test.scratch.be.zmq.WithCallback
    pantheios.1.core
    pantheios.1.util
    pantheios.1.fe.simple
    pantheios.1.be.zmq
    pantheios.1.bec.zmq.WithCallback
    pantheios.1.inserters
    xTests::xTests
  )
  add_test( test.scratch.be.zmq.WithCallback test.scratch.be.zmq.WithCallback )
  add_custom_target( tests DEPENDS test.scratch.be.zmq.WithCallback )

  add_executable( zmqreceiver zmqreceiver.c )
  target_link_libraries( zmqreceiver ${ZeroMQ_LIBRARY} )
endif( ZeroMQ_FOUND )

