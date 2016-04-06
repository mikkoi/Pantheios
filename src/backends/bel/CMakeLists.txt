include_directories (
  ${STLSoft_INCLUDE_DIRS}
)

if( WIN32 )
  add_library(pantheios.1.bel.COMErrorObject bel.COMErrorObject.c )
  list( APPEND Pantheios_BEL_TARGETS_LIST pantheios.1.bel.COMErrorObject )
endif( WIN32 )

add_library(pantheios.1.bel.file bel.file.c )
target_link_libraries( pantheios.1.bel.file pantheios.1.util )
list( APPEND Pantheios_BEL_TARGETS_LIST pantheios.1.bel.file )

add_library(pantheios.1.bel.null bel.null.c )
list( APPEND Pantheios_BEL_TARGETS_LIST pantheios.1.bel.null )

add_library(pantheios.1.bel.syslog bel.syslog.c )
list( APPEND Pantheios_BEL_TARGETS_LIST pantheios.1.bel.syslog )

if( WIN32 )
  add_library(pantheios.1.bel.WindowsConsole bel.WindowsConsole.c )
list( APPEND Pantheios_BEL_TARGETS_LIST pantheios.1.bel.WindowsConsole )
endif( WIN32 )

if( WIN32 )
  add_library(pantheios.1.bel.WindowsEventLog bel.WindowsEventLog.c )
list( APPEND Pantheios_BEL_TARGETS_LIST pantheios.1.bel.WindowsEventLog )
endif( WIN32 )

if( WIN32 )
  add_library(pantheios.1.bel.WindowsSyslog bel.WindowsSyslog.c )
list( APPEND Pantheios_BEL_TARGETS_LIST pantheios.1.bel.WindowsSyslog )
endif( WIN32 )

if( ACE_FOUND )
  add_library(pantheios.1.bel.ACE bel.ACE.c )
  list( APPEND Pantheios_BEL_TARGETS_LIST pantheios.1.bel.ACE )
endif( ACE_FOUND )

add_library(pantheios.1.bel.fail bel.fail.c )
list( APPEND Pantheios_BEL_TARGETS_LIST pantheios.1.bel.fail )

add_library(pantheios.1.bel.fprintf bel.fprintf.c )
list( APPEND Pantheios_BEL_TARGETS_LIST pantheios.1.bel.fprintf )

if( WIN32 )
  add_library(pantheios.1.bel.speech bel.speech.c )
  list( APPEND Pantheios_BEL_TARGETS_LIST pantheios.1.bel.speech )
endif( WIN32 )

add_library(pantheios.1.bel.test bel.test.c )
list( APPEND Pantheios_BEL_TARGETS_LIST pantheios.1.bel.test )

if( WIN32 )
  add_library(pantheios.1.bel.WindowsDebugger bel.WindowsDebugger.c )
  list( APPEND Pantheios_BEL_TARGETS_LIST pantheios.1.bel.WindowsDebugger )
endif( WIN32 )

if( WIN32 )
  add_library(pantheios.1.bel.WindowsMessageBox bel.WindowsMessageBox.c )
  list( APPEND Pantheios_BEL_TARGETS_LIST pantheios.1.bel.WindowsMessageBox )
endif( WIN32 )

if( ZeroMQ_FOUND )
  add_library(pantheios.1.bel.zmq bel.zmq.c )
  list( APPEND Pantheios_BEL_TARGETS_LIST pantheios.1.bel.zmq )
endif( ZeroMQ_FOUND )

set( Pantheios_BEL_TARGETS ${Pantheios_BEL_TARGETS_LIST} PARENT_SCOPE )

