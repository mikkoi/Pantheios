include_directories( ${STLSoft_INCLUDE_DIRS} )

set( Pantheios_FE_TARGETS_LIST "" )

add_library( pantheios.1.fe.all fe.all.c )
# target_link_libraries( pantheios.1.fe.all pantheios.1.util )
list( APPEND Pantheios_FE_TARGETS_LIST "pantheios.1.fe.all" )

add_library( pantheios.1.fe.fail fe.fail.c )
# target_link_libraries( pantheios.1.fe.fail pantheios.1.util )
list( APPEND Pantheios_FE_TARGETS_LIST "pantheios.1.fe.fail" )

add_library( pantheios.1.fe.N fe.N.c )
# target_link_libraries( pantheios.1.fe.N pantheios.1.util )
list( APPEND Pantheios_FE_TARGETS_LIST "pantheios.1.fe.N" )

add_library( pantheios.1.fe.null fe.null.c )
# target_link_libraries( pantheios.1.fe.null pantheios.1.util )
list( APPEND Pantheios_FE_TARGETS_LIST "pantheios.1.fe.null" )

add_library( pantheios.1.fe.simple fe.simple.c )
# target_link_libraries( pantheios.1.fe.simple pantheios.1.util )
list( APPEND Pantheios_FE_TARGETS_LIST "pantheios.1.fe.simple" )

if( WIN32 )
  add_library( pantheios.1.fe.WindowsRegistry fe.WindowsRegistry.cpp )
  # target_link_libraries( pantheios.1.fe.WindowsRegistry pantheios.1.util )
  list( APPEND Pantheios_FE_TARGETS_LIST "pantheios.1.fe.WindowsRegistry" )
endif( WIN32 )

# target_link_libraries( pantheios.1.fe.simple  CxensePantheiosFrontEndIdentity )

set( Pantheios_FE_TARGETS ${Pantheios_FE_TARGETS_LIST} PARENT_SCOPE )

