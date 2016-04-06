include_directories (
  ${STLSoft_INCLUDE_DIRS}
)

if( WIN32 )
  add_library(pantheios.1.be.COMErrorObject be.COMErrorObject.c )
  list( APPEND Pantheios_BE_TARGETS_LIST pantheios.1.be.COMErrorObject )
endif( WIN32 )

add_library(pantheios.1.be.file be.file.c )
list( APPEND Pantheios_BE_TARGETS_LIST pantheios.1.be.file )

add_library(pantheios.1.be.null be.null.c )
list( APPEND Pantheios_BE_TARGETS_LIST pantheios.1.be.null )

add_library(pantheios.1.be.syslog be.syslog.c )
list( APPEND Pantheios_BE_TARGETS_LIST pantheios.1.be.syslog )

if( WIN32 )
  add_library(pantheios.1.be.WindowsConsole be.WindowsConsole.c )
list( APPEND Pantheios_BE_TARGETS_LIST pantheios.1.be.WindowsConsole )
endif( WIN32 )

if( WIN32 )
  add_library(pantheios.1.be.WindowsEventLog be.WindowsEventLog.c )
list( APPEND Pantheios_BE_TARGETS_LIST pantheios.1.be.WindowsEventLog )
endif( WIN32 )

if( WIN32 )
  add_library(pantheios.1.be.WindowsSyslog be.WindowsSyslog.c )
list( APPEND Pantheios_BE_TARGETS_LIST pantheios.1.be.WindowsSyslog )
endif( WIN32 )

if( ACE_FOUND )
  add_library(pantheios.1.be.ACE be.ACE.c )
  list( APPEND Pantheios_BE_TARGETS_LIST pantheios.1.be.ACE )
endif( ACE_FOUND )

add_library(pantheios.1.be.fail be.fail.c )
list( APPEND Pantheios_BE_TARGETS_LIST pantheios.1.be.fail )

add_library(pantheios.1.be.fprintf be.fprintf.c )
list( APPEND Pantheios_BE_TARGETS_LIST pantheios.1.be.fprintf )

if( WIN32 )
  add_library(pantheios.1.be.speech be.speech.c )
  list( APPEND Pantheios_BE_TARGETS_LIST pantheios.1.be.speech )
endif( WIN32 )

add_library(pantheios.1.be.test be.test.c )
list( APPEND Pantheios_BE_TARGETS_LIST pantheios.1.be.test )

if( WIN32 )
  add_library(pantheios.1.be.WindowsDebugger be.WindowsDebugger.c )
  list( APPEND Pantheios_BE_TARGETS_LIST pantheios.1.be.WindowsDebugger )
endif( WIN32 )

if( WIN32 )
  add_library(pantheios.1.be.WindowsMessageBox be.WindowsMessageBox.c )
  list( APPEND Pantheios_BE_TARGETS_LIST pantheios.1.be.WindowsMessageBox )
endif( WIN32 )

if( ZeroMQ_FOUND )
  add_library(pantheios.1.be.zmq be.zmq.c )
  list( APPEND Pantheios_BE_TARGETS_LIST pantheios.1.be.zmq )
endif( ZeroMQ_FOUND )

set( Pantheios_BE_TARGETS ${Pantheios_BE_TARGETS_LIST} PARENT_SCOPE )

