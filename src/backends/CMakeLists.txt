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

add_library(pantheios.1.bec.null bec.null.c )
list( APPEND Pantheios_BEC_TARGETS_LIST pantheios.1.bec.null )

add_library(pantheios.1.bec.syslog bec.syslog.c )
list( APPEND Pantheios_BEC_TARGETS_LIST pantheios.1.bec.syslog )

if( WIN32 )
  add_library(pantheios.1.bec.WindowsConsole bec.WindowsConsole.cpp )
list( APPEND Pantheios_BEC_TARGETS_LIST pantheios.1.bec.WindowsConsole )
endif( WIN32 )

if( WIN32 )
  add_library(pantheios.1.bec.WindowsEventLog bec.WindowsEventLog.cpp )
list( APPEND Pantheios_BEC_TARGETS_LIST pantheios.1.bec.WindowsEventLog )
endif( WIN32 )

if( WIN32 )
  add_library(pantheios.1.bec.WindowsSyslog bec.WindowsSyslog.cpp )
list( APPEND Pantheios_BEC_TARGETS_LIST pantheios.1.bec.WindowsSyslog )
endif( WIN32 )

add_library(pantheios.1.be.lrsplit be.lrsplit.c )
list( APPEND Pantheios_BEC_TARGETS_LIST pantheios.1.be.lrsplit )

if( ACE_FOUND )
  add_library(pantheios.1.bec.ACE bec.ACE.cpp )
  list( APPEND Pantheios_BEC_TARGETS_LIST pantheios.1.bec.ACE )
endif( ACE_FOUND )

add_library(pantheios.1.bec.fail bec.fail.c )
list( APPEND Pantheios_BEC_TARGETS_LIST pantheios.1.bec.fail )

add_library(pantheios.1.bec.fprintf bec.fprintf.cpp )
list( APPEND Pantheios_BEC_TARGETS_LIST pantheios.1.bec.fprintf )

if( WIN32 )
  add_library(pantheios.1.bec.speech bec.speech.cpp )
  list( APPEND Pantheios_BEC_TARGETS_LIST pantheios.1.bec.speech )
endif( WIN32 )

add_library(pantheios.1.bec.test bec.test.cpp )
list( APPEND Pantheios_BEC_TARGETS_LIST pantheios.1.bec.test )

if( WIN32 )
  add_library(pantheios.1.bec.WindowsDebugger bec.WindowsDebugger.cpp )
  list( APPEND Pantheios_BEC_TARGETS_LIST pantheios.1.bec.WindowsDebugger )
endif( WIN32 )

if( WIN32 )
  add_library(pantheios.1.bec.WindowsMessageBox bec.WindowsMessageBox.cpp )
  list( APPEND Pantheios_BEC_TARGETS_LIST pantheios.1.bec.WindowsMessageBox )
endif( WIN32 )

set( Pantheios_BEC_TARGETS ${Pantheios_BEC_TARGETS_LIST} PARENT_SCOPE )

