add_library(pantheios.1.core
    api.cpp api.deprecated.c api.exitprocess.cpp
    api.logputs.cpp auto.cpp logprintf.c)
target_link_libraries(pantheios.1.core STLSoft::STLSoft)
target_include_directories(pantheios.1.core PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)

install(TARGETS pantheios.1.core
    EXPORT project-targets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

