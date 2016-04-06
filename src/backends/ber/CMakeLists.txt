include_directories (
  ${STLSoft_INCLUDE_DIRS}
)

if( WIN32 )
  add_library(pantheios.1.ber.COMErrorObject ber.COMErrorObject.c )
  list( APPEND Pantheios_BER_TARGETS_LIST pantheios.1.ber.COMErrorObject )
endif( WIN32 )

add_library(pantheios.1.ber.file ber.file.c )
target_link_libraries( pantheios.1.ber.file pantheios.1.util )
list( APPEND Pantheios_BER_TARGETS_LIST pantheios.1.ber.file )

add_library(pantheios.1.ber.null ber.null.c )
list( APPEND Pantheios_BER_TARGETS_LIST pantheios.1.ber.null )

add_library(pantheios.1.ber.syslog ber.syslog.c )
list( APPEND Pantheios_BER_TARGETS_LIST pantheios.1.ber.syslog )

if( WIN32 )
  add_library(pantheios.1.ber.WindowsConsole ber.WindowsConsole.c )
list( APPEND Pantheios_BER_TARGETS_LIST pantheios.1.ber.WindowsConsole )
endif( WIN32 )

if( WIN32 )
  add_library(pantheios.1.ber.WindowsEventLog ber.WindowsEventLog.c )
list( APPEND Pantheios_BER_TARGETS_LIST pantheios.1.ber.WindowsEventLog )
endif( WIN32 )

if( WIN32 )
  add_library(pantheios.1.ber.WindowsSyslog ber.WindowsSyslog.c )
list( APPEND Pantheios_BER_TARGETS_LIST pantheios.1.ber.WindowsSyslog )
endif( WIN32 )

if( ACE_FOUND )
  add_library(pantheios.1.ber.ACE ber.ACE.c )
  list( APPEND Pantheios_BER_TARGETS_LIST pantheios.1.ber.ACE )
endif( ACE_FOUND )

add_library(pantheios.1.ber.fail ber.fail.c )
list( APPEND Pantheios_BER_TARGETS_LIST pantheios.1.ber.fail )

add_library(pantheios.1.ber.fprintf ber.fprintf.c )
list( APPEND Pantheios_BER_TARGETS_LIST pantheios.1.ber.fprintf )

if( WIN32 )
  add_library(pantheios.1.ber.speech ber.speech.c )
  list( APPEND Pantheios_BER_TARGETS_LIST pantheios.1.ber.speech )
endif( WIN32 )

add_library(pantheios.1.ber.test ber.test.c )
list( APPEND Pantheios_BER_TARGETS_LIST pantheios.1.ber.test )

if( WIN32 )
  add_library(pantheios.1.ber.WindowsDebugger ber.WindowsDebugger.c )
  list( APPEND Pantheios_BER_TARGETS_LIST pantheios.1.ber.WindowsDebugger )
endif( WIN32 )

if( WIN32 )
  add_library(pantheios.1.ber.WindowsMessageBox ber.WindowsMessageBox.c )
  list( APPEND Pantheios_BER_TARGETS_LIST pantheios.1.ber.WindowsMessageBox )
endif( WIN32 )

set( Pantheios_BER_TARGETS ${Pantheios_BER_TARGETS_LIST} PARENT_SCOPE )

