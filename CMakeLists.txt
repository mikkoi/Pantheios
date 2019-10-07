cmake_minimum_required(VERSION 3.9 FATAL_ERROR)
if(POLICY CMP0074)
    cmake_policy(SET CMP0074 NEW) # Use <PackageName>_ROOT variables
endif()
project(Pantheios
  DESCRIPTION "The C/C++ Diagnostic Logging Sweetspot"
  LANGUAGES C CXX)

# Directory for CMake specific extensions and source files.
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# Set build type to Debug if this is a Git repository.
# Otherwise set to Release.
# Unless user overrides on the command line.
include(BuildType)

# Configure a project for testing with CTest/CDash.
# Activate testing (var BUILD_TESTING).
# unless user overrides on the command line.
include(CTest)

# Handle version number
set(RX_WS "[ \t\r\n]")
file(READ "${CMAKE_CURRENT_SOURCE_DIR}/include/pantheios/pantheios.h" _header_file)
string(REGEX MATCH "#define${RX_WS}+PANTHEIOS_VER_MAJOR${RX_WS}+([0-9]+)" MAJOR_DUMMY ${_header_file})
set(_VERSION_MAJOR ${CMAKE_MATCH_1})
string(REGEX MATCH "#define${RX_WS}+PANTHEIOS_VER_MINOR${RX_WS}+([0-9]+)" MINOR_DUMMY ${_header_file})
set(_VERSION_MINOR ${CMAKE_MATCH_1})
string(REGEX MATCH "#define${RX_WS}+PANTHEIOS_VER_REVISION${RX_WS}+([0-9]+)" PATCH_DUMMY ${_header_file})
set(_VERSION_PATCH ${CMAKE_MATCH_1})

# Set project version number here
set(PROJECT_VERSION_MAJOR ${_VERSION_MAJOR})
set(PROJECT_VERSION_MINOR ${_VERSION_MINOR})
set(PROJECT_VERSION_PATCH ${_VERSION_PATCH})
set(PROJECT_VERSION "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}")

# Adhere strictly to C and C++ standards plus extensions.
set(CMAKE_C_STANDARD 90)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON) # GNU extensions and POSIX standard
set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

# #########################################################
# Preparations for installing

# Provides install directory variables as defined by the GNU Coding Standards.
include(GNUInstallDirs)

# Build
option( PANTHEIOS_USE_WIDE_STRINGS "Build Pantheois with wide string support." Off )
if( PANTHEIOS_USE_WIDE_STRINGS )
  set_property( GLOBAL PROPERTY COMPILE_DEFINITIONS PANTHEIOS_USE_WIDE_STRINGS=1 )
endif( PANTHEIOS_USE_WIDE_STRINGS )

find_package(STLSoft 1.9.121 REQUIRED)
find_package(b64 1.4 REQUIRED)
find_package(shwild 0.10.1 QUIET)
find_package(xCover 0.3.3 QUIET)
find_package(ACE QUIET)
find_package(Pantheios.Extras QUIET)

# The library
add_subdirectory(src)

# Tests
if(BUILD_TESTING)
    find_package(xTests 0.18.4 QUIET)
    if(xTests_FOUND)
        add_subdirectory(test)
    else()
        message(AUTHOR_WARNING "The xTests framework not found. Cannot build tests.")
    endif()
endif()

# Examples
option(BUILD_EXAMPLES "Build the example programs" ON)
if(BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()

# #########################################################
# Export and install the project

string(TOLOWER ${PROJECT_NAME} EXPORT_NAME)

# Prepare a config and config-version files
include(CMakePackageConfigHelpers)
configure_package_config_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/cmake/${EXPORT_NAME}-config.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/cmake/${EXPORT_NAME}-config.cmake
  INSTALL_DESTINATION ${LIB_INSTALL_DIR}/${EXPORT_NAME}/cmake
)
write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/cmake/${EXPORT_NAME}-config-version.cmake
  VERSION ${PROJECT_VERSION}
  COMPATIBILITY AnyNewerVersion
)

export(EXPORT project-targets
    FILE "${CMAKE_CURRENT_BINARY_DIR}/cmake/${EXPORT_NAME}-targets.cmake"
    NAMESPACE "${PROJECT_NAME}::"
)

# Install to GNU type subdirs under CMAKE_INSTALL_PREFIX
install(EXPORT project-targets
    NAMESPACE "${PROJECT_NAME}::"
    FILE "${EXPORT_NAME}-targets.cmake"
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${EXPORT_NAME}
)
install( FILES
    "${CMAKE_CURRENT_BINARY_DIR}/cmake/${EXPORT_NAME}-config.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/cmake/${EXPORT_NAME}-config-version.cmake"
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${EXPORT_NAME}
)

# Store the current build directory in the CMake
# user package registry for package.
# This helps dependent projects use a package
# from the current project’s build tree,
# i.e. without installing it.
export(PACKAGE "${PROJECT_NAME}")


# cmake_minimum_required( VERSION 2.8 )
# project( Pantheios C CXX )
# enable_testing()
# set( Pantheios_VERSION 1.0.1.216 )
#
# option( PANTHEIOS_USE_WIDE_STRINGS "Build Pantheois with wide string support." Off )
# if( PANTHEIOS_USE_WIDE_STRINGS )
#   set_property( GLOBAL PROPERTY COMPILE_DEFINITIONS PANTHEIOS_USE_WIDE_STRINGS=1 )
# endif( PANTHEIOS_USE_WIDE_STRINGS )
#
# # Project include directory
# include_directories( "${CMAKE_CURRENT_SOURCE_DIR}/include" )
#
# find_package( STLSoft 1.9.121 REQUIRED )
# find_package( b64 1.4 REQUIRED )
# find_package( shwild 0.10.1 QUIET )
# find_package( xCover 0.3.3 QUIET )
# find_package( xTests 0.18.4 CONFIG QUIET )
# if( NOT xTests_FOUND )
#   message( AUTHOR_WARNING "The xTests framework not found. Cannot build tests." )
# endif()
# find_package( ACE QUIET )
# find_package( Pantheios.Extras QUIET )
#
# add_subdirectory( src/backends )
# add_subdirectory( src/backends/be )
# add_subdirectory( src/backends/bel )
# add_subdirectory( src/backends/ber )
# add_subdirectory( src/core )
# add_subdirectory( src/frontends )
# add_subdirectory( src/inserters )
# add_subdirectory( src/util )
#
# if( xTests_FOUND )
#   add_subdirectory( test EXCLUDE_FROM_ALL )
# endif( xTests_FOUND )
#
# add_subdirectory( examples EXCLUDE_FROM_ALL )
#
# set( CMAKE_INCLUDE_CURRENT_DIR ON )
#
# include( CMakePackageConfigHelpers )
#
# install(
#   DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/include"
#   DESTINATION ${CMAKE_INSTALL_PREFIX}
#   COMPONENT Devel
# )
#
# write_basic_package_version_file(
#   "${CMAKE_CURRENT_BINARY_DIR}/cmake/PantheiosConfigVersion.cmake"
#   VERSION ${Pantheios_VERSION}
#   COMPATIBILITY AnyNewerVersion
# )
#
# export( TARGETS
#     pantheios.1.core
#     pantheios.1.util
#     pantheios.1.inserters
#     ${Pantheios_FE_TARGETS}
#     ${Pantheios_BEC_TARGETS}
#     ${Pantheios_BE_TARGETS}
#     ${Pantheios_BEL_TARGETS}
#     ${Pantheios_BER_TARGETS}
#   FILE "${CMAKE_CURRENT_BINARY_DIR}/cmake/PantheiosTargets.cmake"
#   NAMESPACE Pantheios::
# )
# set( PACKAGE_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include" )
# configure_file( cmake/PantheiosConfig.cmake.in
#   "${CMAKE_CURRENT_BINARY_DIR}/cmake/PantheiosConfig.cmake"
#   @ONLY
# )
# export( PACKAGE Pantheios )
#
# set( ConfigPackageLocation cmake/Pantheios )
# install( FILES
#     "${CMAKE_CURRENT_BINARY_DIR}/cmake/PantheiosConfig.cmake"
#     "${CMAKE_CURRENT_BINARY_DIR}/cmake/PantheiosConfigVersion.cmake"
#   DESTINATION ${ConfigPackageLocation}
#   COMPONENT Devel
# )
#
