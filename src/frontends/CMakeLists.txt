add_library( pantheios.1.fe.all fe.all.c )
target_link_libraries(pantheios.1.fe.all STLSoft::STLSoft)
target_include_directories(pantheios.1.fe.all PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)

add_library( pantheios.1.fe.all.withcallback fe.all.c )
target_link_libraries(pantheios.1.fe.all.withcallback STLSoft::STLSoft)
set_target_properties( pantheios.1.fe.all.withcallback
   PROPERTIES COMPILE_DEFINITIONS PANTHEIOS_BE_USE_CALLBACK )
target_include_directories(pantheios.1.fe.all.withcallback PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)

add_library( pantheios.1.fe.fail fe.fail.c )
target_link_libraries(pantheios.1.fe.fail STLSoft::STLSoft)
target_include_directories(pantheios.1.fe.fail PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)

add_library( pantheios.1.fe.N fe.N.c )
target_link_libraries(pantheios.1.fe.N STLSoft::STLSoft)
target_include_directories(pantheios.1.fe.N PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)

add_library( pantheios.1.fe.N.withcallback fe.N.c )
target_link_libraries(pantheios.1.fe.N.withcallback STLSoft::STLSoft)
set_target_properties( pantheios.1.fe.N.withcallback
   PROPERTIES COMPILE_DEFINITIONS PANTHEIOS_BE_USE_CALLBACK )
target_include_directories(pantheios.1.fe.N.withcallback PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)

add_library( pantheios.1.fe.null fe.null.c )
target_link_libraries(pantheios.1.fe.null STLSoft::STLSoft)
target_include_directories(pantheios.1.fe.null PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)

add_library( pantheios.1.fe.null.withcallback fe.null.c )
target_link_libraries(pantheios.1.fe.null.withcallback STLSoft::STLSoft)
set_target_properties( pantheios.1.fe.null.withcallback
   PROPERTIES COMPILE_DEFINITIONS PANTHEIOS_BE_USE_CALLBACK )
target_include_directories(pantheios.1.fe.null.withcallback PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)

add_library( pantheios.1.fe.simple fe.simple.c )
target_link_libraries(pantheios.1.fe.simple STLSoft::STLSoft)
target_include_directories(pantheios.1.fe.simple PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)

add_library( pantheios.1.fe.simple.withcallback fe.simple.c )
target_link_libraries(pantheios.1.fe.simple.withcallback STLSoft::STLSoft)
set_target_properties( pantheios.1.fe.simple.withcallback
    PROPERTIES COMPILE_DEFINITIONS PANTHEIOS_BE_USE_CALLBACK )
target_link_libraries(pantheios.1.fe.simple.withcallback STLSoft::STLSoft)
target_include_directories(pantheios.1.fe.simple.withcallback PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)

if( WIN32 )
    add_library( pantheios.1.fe.WindowsRegistry fe.WindowsRegistry.cpp )
    target_link_libraries(pantheios.1.fe.WindowsRegistry STLSoft::STLSoft)
    add_library( pantheios.1.fe.WindowsRegistry.withcallback fe.WindowsRegistry.cpp )
    target_link_libraries(pantheios.1.fe.WindowsRegistry.withcallback STLSoft::STLSoft)
    set_target_properties( pantheios.1.fe.WindowsRegistry.withcallback
        PROPERTIES COMPILE_DEFINITIONS PANTHEIOS_BE_USE_CALLBACK )
endif( WIN32 )

install(TARGETS
    pantheios.1.fe.all
    pantheios.1.fe.all.withcallback
    pantheios.1.fe.fail
    pantheios.1.fe.N
    pantheios.1.fe.N.withcallback
    pantheios.1.fe.null
    pantheios.1.fe.null.withcallback
    pantheios.1.fe.simple
    pantheios.1.fe.simple.withcallback
    EXPORT project-targets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

