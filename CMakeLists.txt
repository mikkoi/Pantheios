cmake_minimum_required( VERSION 2.8 )
project( Pantheios C CXX )
enable_testing()
set( Pantheios_VERSION 1.0.1.216 )

# set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DPANTHEIOS_USE_WIDE_STRINGS")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DPANTHEIOS_BE_USE_CALLBACK" CACHE STRING "" FORCE)
# set(CMAKE_C_FLAGS "${CMAKE_CXX_FLAGS} -DPANTHEIOS_BE_USE_CALLBACK" CACHE STRING "" FORCE)

# Project include directory
include_directories( "${CMAKE_CURRENT_SOURCE_DIR}/include" )

find_package( STLSoft 1.9.121 REQUIRED )
find_package( b64 1.4 REQUIRED )
find_package( shwild 0.10.1 QUIET )
find_package( xCover 0.3.3 QUIET )
find_package( xTests 0.18.4 CONFIG QUIET )
if( NOT xTests_FOUND )
   message( AUTHOR_WARNING "The xTests framework not found. Cannot build tests." )
endif()
find_package( ACE QUIET )

add_subdirectory( src/backends )
add_subdirectory( src/backends/be )
add_subdirectory( src/backends/bel )
add_subdirectory( src/backends/ber )
add_subdirectory( src/core )
add_subdirectory( src/frontends )
add_subdirectory( src/inserters )
add_subdirectory( src/util )

if( xTests_FOUND )
   add_subdirectory(test EXCLUDE_FROM_ALL)
endif( xTests_FOUND )

set( CMAKE_INCLUDE_CURRENT_DIR ON )
set( CMAKE_INCLUDE_CURRENT_DIR_IN_INTERFACE ON )

# include(GenerateExportHeader)
include( CMakePackageConfigHelpers )

# include_directories( ${STLSoft_INCLUDE_DIRS} )
# add_library(Pantheios
#    src/api.cpp
#    src/fmt_cache.cpp
#    src/fmt_spec_defect_handlers.cpp
#    src/init_code_strings.cpp
#    src/memory_pool.cpp
#    src/replacements.cpp
#    src/snprintf.cpp
# )
# add_dependencies( Pantheios STLSoft )
# generate_export_header(Pantheios)
# set_property(TARGET Pantheios PROPERTY VERSION ${Pantheios_VERSION})
# set_property(TARGET Pantheios PROPERTY SOVERSION 3)
# set_property(TARGET Pantheios PROPERTY
#   INTERFACE_Pantheios_MAJOR_VERSION 3)
# set_property(TARGET Pantheios APPEND PROPERTY
#   COMPATIBLE_INTERFACE_STRING Pantheios_MAJOR_VERSION
# )
#
# install(TARGETS Pantheios EXPORT PantheiosTargets
#   LIBRARY DESTINATION lib
#   ARCHIVE DESTINATION lib
#   RUNTIME DESTINATION bin
# )
install(
  DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/include"
  DESTINATION ${CMAKE_INSTALL_PREFIX}
  COMPONENT Devel
)

write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/cmake/PantheiosConfigVersion.cmake"
  VERSION ${Pantheios_VERSION}
  COMPATIBILITY AnyNewerVersion
)

export(TARGETS
    pantheios.1.core
    pantheios.1.util
    pantheios.1.inserters
    ${Pantheios_FE_TARGETS}
    ${Pantheios_BEC_TARGETS}
    ${Pantheios_BE_TARGETS}
    ${Pantheios_BEL_TARGETS}
    ${Pantheios_BER_TARGETS}
  FILE "${CMAKE_CURRENT_BINARY_DIR}/cmake/PantheiosTargets.cmake"
  NAMESPACE Pantheios::
)
set(PACKAGE_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
configure_file(cmake/PantheiosConfig.cmake.in
  "${CMAKE_CURRENT_BINARY_DIR}/cmake/PantheiosConfig.cmake"
  @ONLY
)
export(PACKAGE Pantheios)

set(ConfigPackageLocation cmake/Pantheios)
# install(EXPORT PantheiosTargets
#   FILE PantheiosTargets.cmake
#   NAMESPACE Pantheios::
#   DESTINATION ${ConfigPackageLocation}
# )
install( FILES
    "${CMAKE_CURRENT_BINARY_DIR}/cmake/PantheiosConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/cmake/PantheiosConfigVersion.cmake"
  DESTINATION ${ConfigPackageLocation}
  COMPONENT Devel
)

