include_directories (
  ${STLSoft_INCLUDE_DIRS}
  ${b64_INCLUDE_DIRS}
)

if( WIN32 )
  add_library(pantheios.1.bec.COMErrorObject bec.COMErrorObject.cpp )
  list( APPEND Pantheios_BEC_TARGETS_LIST pantheios.1.bec.COMErrorObject )
endif( WIN32 )

add_library(pantheios.1.bec.file bec.file.cpp )
target_link_libraries( pantheios.1.bec.file pantheios.1.util )
list( APPEND Pantheios_BEC_TARGETS_LIST pantheios.1.bec.file )

add_library( pantheios.1.bec.file.WithCallback bec.file.cpp )
set_target_properties( pantheios.1.bec.file.WithCallback
  PROPERTIES COMPILE_DEFINITIONS PANTHEIOS_BE_USE_CALLBACK )
list( APPEND Pantheios_FE_TARGETS_LIST "pantheios.1.bec.file.WithCallback" )

add_library(pantheios.1.bec.null bec.null.c )
list( APPEND Pantheios_BEC_TARGETS_LIST pantheios.1.bec.null )

add_library(pantheios.1.bec.syslog bec.syslog.c )
list( APPEND Pantheios_BEC_TARGETS_LIST pantheios.1.bec.syslog )

add_library( pantheios.1.bec.syslog.WithCallback bec.syslog.c )
set_target_properties( pantheios.1.bec.syslog.WithCallback
   PROPERTIES COMPILE_DEFINITIONS PANTHEIOS_BE_USE_CALLBACK )
list( APPEND Pantheios_FE_TARGETS_LIST "pantheios.1.bec.syslog.WithCallback" )

if( WIN32 )
  add_library(pantheios.1.bec.WindowsConsole bec.WindowsConsole.cpp )
list( APPEND Pantheios_BEC_TARGETS_LIST pantheios.1.bec.WindowsConsole )

  add_library( pantheios.1.bec.WindowsConsole.WithCallback bec.WindowsConsole.cpp )
  set_target_properties( pantheios.1.bec.WindowsConsole.WithCallback
    PROPERTIES COMPILE_DEFINITIONS PANTHEIOS_BE_USE_CALLBACK )
  list( APPEND Pantheios_FE_TARGETS_LIST "pantheios.1.bec.WindowsConsole.WithCallback" )
endif( WIN32 )

if( WIN32 )
  add_library(pantheios.1.bec.WindowsEventLog bec.WindowsEventLog.cpp )
  list( APPEND Pantheios_BEC_TARGETS_LIST pantheios.1.bec.WindowsEventLog )

  add_library( pantheios.1.bec.WindowsEventLog.WithCallback bec.WindowsEventLog.cpp )
  set_target_properties( pantheios.1.bec.WindowsEventLog.WithCallback
    PROPERTIES COMPILE_DEFINITIONS PANTHEIOS_BE_USE_CALLBACK )
  list( APPEND Pantheios_FE_TARGETS_LIST "pantheios.1.bec.WindowsEventLog.WithCallback" )
endif( WIN32 )

if( WIN32 )
  add_library(pantheios.1.bec.WindowsSyslog bec.WindowsSyslog.cpp )
  list( APPEND Pantheios_BEC_TARGETS_LIST pantheios.1.bec.WindowsSyslog )

  add_library( pantheios.1.bec.WindowsSyslog.WithCallback bec.WindowsSyslog.cpp )
  set_target_properties( pantheios.1.bec.WindowsSyslog.WithCallback
    PROPERTIES COMPILE_DEFINITIONS PANTHEIOS_BE_USE_CALLBACK )
  list( APPEND Pantheios_FE_TARGETS_LIST "pantheios.1.bec.WindowsSyslog.WithCallback" )
endif( WIN32 )

add_library(pantheios.1.be.N be.N.c )
list( APPEND Pantheios_BEC_TARGETS_LIST pantheios.1.be.N )

add_library(pantheios.1.be.lrsplit be.lrsplit.c )
list( APPEND Pantheios_BEC_TARGETS_LIST pantheios.1.be.lrsplit )

if( ACE_FOUND )
  include_directories ( ${ACE_INCLUDE_DIRS} )
  add_library(pantheios.1.bec.ACE bec.ACE.cpp )
  list( APPEND Pantheios_BEC_TARGETS_LIST pantheios.1.bec.ACE )

  add_library( pantheios.1.bec.ACE.WithCallback bec.ACE.cpp )
  set_target_properties( pantheios.1.bec.ACE.WithCallback
    PROPERTIES COMPILE_DEFINITIONS PANTHEIOS_BE_USE_CALLBACK )
  list( APPEND Pantheios_FE_TARGETS_LIST "pantheios.1.bec.ACE.WithCallback" )
endif( ACE_FOUND )

add_library(pantheios.1.bec.fail bec.fail.c )
list( APPEND Pantheios_BEC_TARGETS_LIST pantheios.1.bec.fail )

add_library(pantheios.1.bec.fprintf bec.fprintf.cpp )
list( APPEND Pantheios_BEC_TARGETS_LIST pantheios.1.bec.fprintf )

add_library( pantheios.1.bec.fprintf.WithCallback bec.fprintf.cpp )
set_target_properties( pantheios.1.bec.fprintf.WithCallback
  PROPERTIES COMPILE_DEFINITIONS PANTHEIOS_BE_USE_CALLBACK )
list( APPEND Pantheios_FE_TARGETS_LIST "pantheios.1.bec.fprintf.WithCallback" )

if( WIN32 )
  add_library(pantheios.1.bec.speech bec.speech.cpp )
  list( APPEND Pantheios_BEC_TARGETS_LIST pantheios.1.bec.speech )

  add_library( pantheios.1.bec.speech.WithCallback bec.speech.cpp )
  set_target_properties( pantheios.1.bec.speech.WithCallback
    PROPERTIES COMPILE_DEFINITIONS PANTHEIOS_BE_USE_CALLBACK )
  list( APPEND Pantheios_FE_TARGETS_LIST "pantheios.1.bec.speech.WithCallback" )
endif( WIN32 )

add_library(pantheios.1.bec.test bec.test.cpp )
list( APPEND Pantheios_BEC_TARGETS_LIST pantheios.1.bec.test )

if( WIN32 )
  add_library(pantheios.1.bec.WindowsDebugger bec.WindowsDebugger.cpp )
  list( APPEND Pantheios_BEC_TARGETS_LIST pantheios.1.bec.WindowsDebugger )

  add_library( pantheios.1.bec.WindowsDebugger.WithCallback bec.WindowsDebugger.cpp )
  set_target_properties( pantheios.1.bec.WindowsDebugger.WithCallback
    PROPERTIES COMPILE_DEFINITIONS PANTHEIOS_BE_USE_CALLBACK )
  list( APPEND Pantheios_FE_TARGETS_LIST "pantheios.1.bec.WindowsDebugger.WithCallback" )
endif( WIN32 )

if( WIN32 )
  add_library(pantheios.1.bec.WindowsMessageBox bec.WindowsMessageBox.cpp )
  list( APPEND Pantheios_BEC_TARGETS_LIST pantheios.1.bec.WindowsMessageBox )

  add_library( pantheios.1.bec.WindowsMessageBox.WithCallback bec.WindowsMessageBox.cpp )
  set_target_properties( pantheios.1.bec.WindowsMessageBox.WithCallback
    PROPERTIES COMPILE_DEFINITIONS PANTHEIOS_BE_USE_CALLBACK )
  list( APPEND Pantheios_FE_TARGETS_LIST "pantheios.1.bec.WindowsMessageBox.WithCallback" )
endif( WIN32 )

if( ZeroMQ_FOUND )
  include_directories ( ${ZeroMQ_INCLUDE_DIRS} )
  add_library(pantheios.1.bec.zmq bec.zmq.cpp )
  target_link_libraries( pantheios.1.bec.zmq ${ZeroMQ_LIBRARY} )
  list( APPEND Pantheios_BEC_TARGETS_LIST pantheios.1.bec.zmq )

  add_library( pantheios.1.bec.zmq.WithCallback bec.zmq.cpp )
  target_link_libraries( pantheios.1.bec.zmq.WithCallback ${ZeroMQ_LIBRARY} )
  set_target_properties( pantheios.1.bec.zmq.WithCallback
    PROPERTIES COMPILE_DEFINITIONS PANTHEIOS_BE_USE_CALLBACK )
  list( APPEND Pantheios_BEC_TARGETS_LIST pantheios.1.bec.zmq.WithCallback )
endif( ZeroMQ_FOUND )

set( Pantheios_BEC_TARGETS ${Pantheios_BEC_TARGETS_LIST} PARENT_SCOPE )

