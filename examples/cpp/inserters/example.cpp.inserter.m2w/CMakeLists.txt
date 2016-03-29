include_directories(
  ${STLSoft_INCLUDE_DIRS}
)

if( PANTHEIOS_USE_WIDE_STRINGS )
  add_executable( example.cpp.inserter.m2w example.cpp.inserter.m2w.cpp )
  target_link_libraries( example.cpp.inserter.m2w
    pantheios.1.core
    pantheios.1.util
    pantheios.1.fe.simple
    pantheios.1.be.null
    pantheios.1.bec.null
    pantheios.1.inserters.m2w
  )
  add_custom_target( examples DEPENDS example.cpp.inserter.m2w )
endif( PANTHEIOS_USE_WIDE_STRINGS )

