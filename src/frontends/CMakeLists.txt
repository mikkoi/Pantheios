include_directories( ${STLSoft_INCLUDE_DIRS} )

set( Pantheios_FE_TARGETS_LIST "" )

add_library( pantheios.1.fe.all fe.all.c )
list( APPEND Pantheios_FE_TARGETS_LIST "pantheios.1.fe.all" )

add_library( pantheios.1.fe.all.WithCallback fe.all.c )
set_target_properties( pantheios.1.fe.all.WithCallback
   PROPERTIES COMPILE_DEFINITIONS PANTHEIOS_BE_USE_CALLBACK )
list( APPEND Pantheios_FE_TARGETS_LIST "pantheios.1.fe.all.WithCallback" )

add_library( pantheios.1.fe.fail fe.fail.c )
list( APPEND Pantheios_FE_TARGETS_LIST "pantheios.1.fe.fail" )

add_library( pantheios.1.fe.N fe.N.c )
list( APPEND Pantheios_FE_TARGETS_LIST "pantheios.1.fe.N" )

add_library( pantheios.1.fe.N.WithCallback fe.N.c )
set_target_properties( pantheios.1.fe.N.WithCallback
   PROPERTIES COMPILE_DEFINITIONS PANTHEIOS_BE_USE_CALLBACK )
list( APPEND Pantheios_FE_TARGETS_LIST "pantheios.1.fe.N.WithCallback" )

add_library( pantheios.1.fe.null fe.null.c )
list( APPEND Pantheios_FE_TARGETS_LIST "pantheios.1.fe.null" )

add_library( pantheios.1.fe.null.WithCallback fe.null.c )
set_target_properties( pantheios.1.fe.null.WithCallback
   PROPERTIES COMPILE_DEFINITIONS PANTHEIOS_BE_USE_CALLBACK )
list( APPEND Pantheios_FE_TARGETS_LIST "pantheios.1.fe.null.WithCallback" )

add_library( pantheios.1.fe.simple fe.simple.c )
list( APPEND Pantheios_FE_TARGETS_LIST "pantheios.1.fe.simple" )

add_library( pantheios.1.fe.simple.WithCallback fe.simple.c )
set_target_properties( pantheios.1.fe.simple.WithCallback
   PROPERTIES COMPILE_DEFINITIONS PANTHEIOS_BE_USE_CALLBACK )
list( APPEND Pantheios_FE_TARGETS_LIST "pantheios.1.fe.simple.WithCallback" )

if( WIN32 )
  add_library( pantheios.1.fe.WindowsRegistry fe.WindowsRegistry.cpp )
  list( APPEND Pantheios_FE_TARGETS_LIST "pantheios.1.fe.WindowsRegistry" )
  add_library( pantheios.1.fe.WindowsRegistry.WithCallback fe.WindowsRegistry.cpp )
   set_target_properties( pantheios.1.fe.WindowsRegistry.WithCallback
      PROPERTIES COMPILE_DEFINITIONS PANTHEIOS_BE_USE_CALLBACK )
  list( APPEND Pantheios_FE_TARGETS_LIST "pantheios.1.fe.WindowsRegistry.WithCallback" )
endif( WIN32 )

set( Pantheios_FE_TARGETS ${Pantheios_FE_TARGETS_LIST} PARENT_SCOPE )

