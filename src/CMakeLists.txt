add_subdirectory(backends)
add_subdirectory(core)
add_subdirectory(frontends)
# add_subdirectory(inserters)
add_subdirectory(util)

# There is so many headers, we have to manually copy them.
install(DIRECTORY
    ${CMAKE_SOURCE_DIR}/include/pantheios
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

