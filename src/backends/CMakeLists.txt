if(WIN32)
    add_library(pantheios.1.bec.COMErrorObject bec.COMErrorObject.cpp)
    list(APPEND Pantheios_BEC_TARGETS_LIST pantheios.1.bec.COMErrorObject)
endif(WIN32)

add_library(pantheios.1.bec.file bec.file.cpp)
target_link_libraries(pantheios.1.bec.file pantheios.1.util)
target_link_libraries(pantheios.1.bec.file STLSoft::STLSoft)
list(APPEND Pantheios_BEC_TARGETS_LIST pantheios.1.bec.file)

# set_target_properties(b64 PROPERTIES
#     OUTPUT_NAME "b64.core"
#     PUBLIC_HEADER ${CMAKE_SOURCE_DIR}/include/b64/b64.h)

add_library(pantheios.1.bec.file.WithCallback bec.file.cpp)
target_link_libraries(pantheios.1.bec.file.WithCallback STLSoft::STLSoft)
set_target_properties(pantheios.1.bec.file.WithCallback
    PROPERTIES COMPILE_DEFINITIONS PANTHEIOS_BE_USE_CALLBACK)
list(APPEND Pantheios_BEC_TARGETS_LIST pantheios.1.bec.file.WithCallback)

add_library(pantheios.1.bec.null bec.null.c)
target_link_libraries(pantheios.1.bec.null STLSoft::STLSoft)
list(APPEND Pantheios_BEC_TARGETS_LIST pantheios.1.bec.null)

add_library(pantheios.1.bec.syslog bec.syslog.c)
target_link_libraries(pantheios.1.bec.syslog STLSoft::STLSoft)
list(APPEND Pantheios_BEC_TARGETS_LIST pantheios.1.bec.syslog)

add_library(pantheios.1.bec.syslog.WithCallback bec.syslog.c)
target_link_libraries(pantheios.1.bec.syslog.WithCallback STLSoft::STLSoft)
set_target_properties(pantheios.1.bec.syslog.WithCallback
    PROPERTIES COMPILE_DEFINITIONS PANTHEIOS_BE_USE_CALLBACK)
list(APPEND Pantheios_BEC_TARGETS_LIST pantheios.1.bec.syslog.WithCallback)

if(WIN32)
    add_library(pantheios.1.bec.WindowsConsole bec.WindowsConsole.cpp)
    target_link_libraries(pantheios.1.bec.WindowsConsole STLSoft::STLSoft)
    list(APPEND Pantheios_BEC_TARGETS_LIST pantheios.1.bec.WindowsConsole)

    add_library(pantheios.1.bec.WindowsConsole.WithCallback bec.WindowsConsole.cpp)
    target_link_libraries(pantheios.1.bec.WindowsConsole.WithCallback STLSoft::STLSoft)
    set_target_properties(pantheios.1.bec.WindowsConsole.WithCallback
        PROPERTIES COMPILE_DEFINITIONS PANTHEIOS_BE_USE_CALLBACK)
    list(APPEND Pantheios_BEC_TARGETS_LIST pantheios.1.bec.WindowsConsole.WithCallback)
endif(WIN32)

if(WIN32)
    add_library(pantheios.1.bec.WindowsEventLog bec.WindowsEventLog.cpp)
    target_link_libraries(pantheios.1.bec.WindowsEventLog STLSoft::STLSoft)
    list(APPEND Pantheios_BEC_TARGETS_LIST pantheios.1.bec.WindowsEventLog)

    add_library(pantheios.1.bec.WindowsEventLog.WithCallback bec.WindowsEventLog.cpp)
    set_target_properties(pantheios.1.bec.WindowsEventLog.WithCallback
        PROPERTIES COMPILE_DEFINITIONS PANTHEIOS_BE_USE_CALLBACK)
    list(APPEND Pantheios_BEC_TARGETS_LIST pantheios.1.bec.WindowsEventLog.WithCallback)
endif(WIN32)

if(WIN32)
    add_library(pantheios.1.bec.WindowsSyslog bec.WindowsSyslog.cpp)
    list(APPEND Pantheios_BEC_TARGETS_LIST pantheios.1.bec.WindowsSyslog)

    add_library(pantheios.1.bec.WindowsSyslog.WithCallback bec.WindowsSyslog.cpp)
    set_target_properties(pantheios.1.bec.WindowsSyslog.WithCallback
        PROPERTIES COMPILE_DEFINITIONS PANTHEIOS_BE_USE_CALLBACK)
    list(APPEND Pantheios_BEC_TARGETS_LIST pantheios.1.bec.WindowsSyslog.WithCallback)
endif(WIN32)

add_library(pantheios.1.be.N be.N.c)
target_link_libraries(pantheios.1.be.N STLSoft::STLSoft)
list(APPEND Pantheios_BEC_TARGETS_LIST pantheios.1.be.N)

add_library(pantheios.1.be.lrsplit be.lrsplit.c)
target_link_libraries(pantheios.1.be.lrsplit STLSoft::STLSoft)
list(APPEND Pantheios_BEC_TARGETS_LIST pantheios.1.be.lrsplit)

if(ACE_FOUND)
    include_directories (${ACE_INCLUDE_DIRS})
    add_library(pantheios.1.bec.ACE bec.ACE.cpp)
    list(APPEND Pantheios_BEC_TARGETS_LIST pantheios.1.bec.ACE)

    add_library(pantheios.1.bec.ACE.WithCallback bec.ACE.cpp)
    set_target_properties(pantheios.1.bec.ACE.WithCallback
        PROPERTIES COMPILE_DEFINITIONS PANTHEIOS_BE_USE_CALLBACK)
    list(APPEND Pantheios_BEC_TARGETS_LIST pantheios.1.bec.ACE.WithCallback)
endif(ACE_FOUND)

add_library(pantheios.1.bec.fail bec.fail.c)
target_link_libraries(pantheios.1.bec.fail STLSoft::STLSoft)
list(APPEND Pantheios_BEC_TARGETS_LIST pantheios.1.bec.fail)

add_library(pantheios.1.bec.fprintf bec.fprintf.cpp)
target_link_libraries(pantheios.1.bec.fprintf STLSoft::STLSoft)
list(APPEND Pantheios_BEC_TARGETS_LIST pantheios.1.bec.fprintf)

add_library(pantheios.1.bec.fprintf.WithCallback bec.fprintf.cpp)
target_link_libraries(pantheios.1.bec.fprintf.WithCallback STLSoft::STLSoft)
set_target_properties(pantheios.1.bec.fprintf.WithCallback
    PROPERTIES COMPILE_DEFINITIONS PANTHEIOS_BE_USE_CALLBACK)
list(APPEND Pantheios_BEC_TARGETS_LIST pantheios.1.bec.fprintf.WithCallback)

if(WIN32)
    add_library(pantheios.1.bec.speech bec.speech.cpp)
    list(APPEND Pantheios_BEC_TARGETS_LIST pantheios.1.bec.speech)

    add_library(pantheios.1.bec.speech.WithCallback bec.speech.cpp)
    set_target_properties(pantheios.1.bec.speech.WithCallback
        PROPERTIES COMPILE_DEFINITIONS PANTHEIOS_BE_USE_CALLBACK)
    list(APPEND Pantheios_BEC_TARGETS_LIST pantheios.1.bec.speech.WithCallback)
endif(WIN32)

add_library(pantheios.1.bec.test bec.test.cpp)
target_link_libraries(pantheios.1.bec.test STLSoft::STLSoft)
list(APPEND Pantheios_BEC_TARGETS_LIST pantheios.1.bec.test)

if(WIN32)
    add_library(pantheios.1.bec.WindowsDebugger bec.WindowsDebugger.cpp)
    list(APPEND Pantheios_BEC_TARGETS_LIST pantheios.1.bec.WindowsDebugger)

    add_library(pantheios.1.bec.WindowsDebugger.WithCallback bec.WindowsDebugger.cpp)
    set_target_properties(pantheios.1.bec.WindowsDebugger.WithCallback
        PROPERTIES COMPILE_DEFINITIONS PANTHEIOS_BE_USE_CALLBACK)
    list(APPEND Pantheios_BEC_TARGETS_LIST pantheios.1.bec.WindowsDebugger.WithCallback)
endif(WIN32)

if(WIN32)
    add_library(pantheios.1.bec.WindowsMessageBox bec.WindowsMessageBox.cpp)
    list(APPEND Pantheios_BEC_TARGETS_LIST pantheios.1.bec.WindowsMessageBox)

    add_library(pantheios.1.bec.WindowsMessageBox.WithCallback bec.WindowsMessageBox.cpp)
    set_target_properties(pantheios.1.bec.WindowsMessageBox.WithCallback
        PROPERTIES COMPILE_DEFINITIONS PANTHEIOS_BE_USE_CALLBACK)
    list(APPEND Pantheios_BEC_TARGETS_LIST pantheios.1.bec.WindowsMessageBox.WithCallback)
endif(WIN32)

target_include_directories(pantheios.1.bec.file PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)
target_include_directories(pantheios.1.bec.file.WithCallback PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)
target_include_directories( pantheios.1.bec.null PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)
target_include_directories( pantheios.1.bec.null PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)
target_include_directories( pantheios.1.bec.syslog PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)
target_include_directories( pantheios.1.bec.syslog.WithCallback PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)
target_include_directories( pantheios.1.be.N PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)
target_include_directories( pantheios.1.be.lrsplit PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)
target_include_directories( pantheios.1.bec.fail PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)
target_include_directories( pantheios.1.bec.fprintf PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)
target_include_directories( pantheios.1.bec.fprintf.WithCallback PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)
target_include_directories( pantheios.1.bec.test PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)

install(TARGETS
    pantheios.1.bec.file
    pantheios.1.bec.file.WithCallback
    pantheios.1.bec.null
    pantheios.1.bec.syslog
    pantheios.1.bec.syslog.WithCallback
    pantheios.1.be.N
    pantheios.1.be.lrsplit
    pantheios.1.bec.fail
    pantheios.1.bec.fprintf
    pantheios.1.bec.fprintf.WithCallback
    pantheios.1.bec.test
    EXPORT project-targets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

add_subdirectory(be)
# add_subdirectory(bel)
# add_subdirectory(ber)

