cmake_minimum_required( VERSION 2.8 )
project( Pantheios C CXX )
enable_testing()
set( Pantheios_VERSION 1.0.1.216 )

option( PANTHEIOS_USE_WIDE_STRINGS "Build Pantheois with wide string support." Off )
if( PANTHEIOS_USE_WIDE_STRINGS )
  set_property( GLOBAL PROPERTY COMPILE_DEFINITIONS PANTHEIOS_USE_WIDE_STRINGS=1 )
endif( PANTHEIOS_USE_WIDE_STRINGS )

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
find_package( Pantheios.Extras QUIET )
find_library( ZeroMQ_LIBRARY
  NAMES zmq libzmq
  HINTS ${ZeroMQ_ROOT_DIR}/lib
)
find_path( ZeroMQ_INCLUDE_DIRS
  NAMES zmq.h
  HINTS ${ZeroMQ_ROOT_DIR}/include
)
if( ZeroMQ_LIBRARY AND ZeroMQ_INCLUDE_DIRS )
  set( ZeroMQ_FOUND True )
endif( ZeroMQ_LIBRARY AND ZeroMQ_INCLUDE_DIRS )

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

include( CMakePackageConfigHelpers )

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

export( TARGETS
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
set( PACKAGE_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include" )
configure_file( cmake/PantheiosConfig.cmake.in
  "${CMAKE_CURRENT_BINARY_DIR}/cmake/PantheiosConfig.cmake"
  @ONLY
)
export( PACKAGE Pantheios )

set( ConfigPackageLocation cmake/Pantheios )
install( FILES
    "${CMAKE_CURRENT_BINARY_DIR}/cmake/PantheiosConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/cmake/PantheiosConfigVersion.cmake"
  DESTINATION ${ConfigPackageLocation}
  COMPONENT Devel
)

