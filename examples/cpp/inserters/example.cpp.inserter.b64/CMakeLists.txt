include_directories(
  ${STLSoft_INCLUDE_DIRS}
  ${b64_INCLUDE_DIRS}
)

if( b64_FOUND )
  add_executable( example.cpp.inserter.b64 example.cpp.inserter.b64.cpp )
  target_link_libraries( example.cpp.inserter.b64
    pantheios.1.core
    pantheios.1.util
    pantheios.1.fe.simple
    pantheios.1.be.null
    pantheios.1.bec.null
    pantheios.1.inserters
    b64::b64
  )
  add_custom_target( examples DEPENDS example.cpp.inserter.b64 )
endif( b64_FOUND )

