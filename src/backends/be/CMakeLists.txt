if( WIN32 )
    add_library(pantheios.1.be.COMErrorObject be.COMErrorObject.c )
    target_link_libraries(pantheios.1.be.COMErrorObject STLSoft::STLSoft)
    list( APPEND Pantheios_BE_TARGETS_LIST pantheios.1.be.COMErrorObject )
endif( WIN32 )

add_library(pantheios.1.be.file be.file.c )
target_link_libraries(pantheios.1.be.file STLSoft::STLSoft)
target_include_directories( pantheios.1.be.file PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)

add_library(pantheios.1.be.null be.null.c )
target_link_libraries(pantheios.1.be.null STLSoft::STLSoft)
target_include_directories( pantheios.1.be.null PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)

add_library(pantheios.1.be.syslog be.syslog.c )
target_link_libraries(pantheios.1.be.syslog STLSoft::STLSoft)
target_include_directories( pantheios.1.be.syslog PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)

if( WIN32 )
    add_library(pantheios.1.be.WindowsConsole be.WindowsConsole.c )
    target_link_libraries(pantheios.1.be.WindowsConsole STLSoft::STLSoft)
    list( APPEND Pantheios_BE_TARGETS_LIST pantheios.1.be.WindowsConsole )
endif( WIN32 )

if( WIN32 )
    add_library(pantheios.1.be.WindowsEventLog be.WindowsEventLog.c )
    target_link_libraries(pantheios.1.be.WindowsEventLog STLSoft::STLSoft)
    list( APPEND Pantheios_BE_TARGETS_LIST pantheios.1.be.WindowsEventLog )
endif( WIN32 )

if( WIN32 )
    add_library(pantheios.1.be.WindowsSyslog be.WindowsSyslog.c )
    target_link_libraries(pantheios.1.be.WindowsSyslog STLSoft::STLSoft)
    list( APPEND Pantheios_BE_TARGETS_LIST pantheios.1.be.WindowsSyslog )
endif( WIN32 )

if( ACE_FOUND )
    add_library(pantheios.1.be.ACE be.ACE.c )
    target_link_libraries(pantheios.1.be.ACE STLSoft::STLSoft)
    list( APPEND Pantheios_BE_TARGETS_LIST pantheios.1.be.ACE )
endif( ACE_FOUND )

add_library(pantheios.1.be.fail be.fail.c )
target_link_libraries(pantheios.1.be.fail STLSoft::STLSoft)
target_include_directories( pantheios.1.be.fail PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)

add_library(pantheios.1.be.fprintf be.fprintf.c )
target_link_libraries(pantheios.1.be.fprintf STLSoft::STLSoft)
target_include_directories( pantheios.1.be.fprintf PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)

if( WIN32 )
    add_library(pantheios.1.be.speech be.speech.c )
    target_link_libraries(pantheios.1.be.speech STLSoft::STLSoft)
    list( APPEND Pantheios_BE_TARGETS_LIST pantheios.1.be.speech )
endif( WIN32 )

add_library(pantheios.1.be.test be.test.c )
target_link_libraries(pantheios.1.be.test STLSoft::STLSoft)
target_include_directories( pantheios.1.be.test PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)

if( WIN32 )
  add_library(pantheios.1.be.WindowsDebugger be.WindowsDebugger.c )
  target_link_libraries(pantheios.1.be.WindowsDebugger STLSoft::STLSoft)
  list( APPEND Pantheios_BE_TARGETS_LIST pantheios.1.be.WindowsDebugger )
endif( WIN32 )

if( WIN32 )
  add_library(pantheios.1.be.WindowsMessageBox be.WindowsMessageBox.c )
  target_link_libraries(pantheios.1.be.WindowsMessageBox STLSoft::STLSoft)
  list( APPEND Pantheios_BE_TARGETS_LIST pantheios.1.be.WindowsMessageBox )
endif( WIN32 )


install(TARGETS
    pantheios.1.be.file
    pantheios.1.be.null
    pantheios.1.be.syslog
    pantheios.1.be.fail
    pantheios.1.be.fprintf
    pantheios.1.be.test
    EXPORT project-targets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

