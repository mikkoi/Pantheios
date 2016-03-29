include_directories(
  ${STLSoft_INCLUDE_DIRS}
  ${Log4cxx_INCLUDE_DIRS}
)

if( Log4cxx_FOUND ) # N.B. Build does not include FindLog4cxx
add_executable( example.cpp.custom.wrap_log4cxx example.cpp.custom.wrap_log4cxx.cpp )
target_link_libraries( example.cpp.custom.wrap_log4cxx
  pantheios.1.core
  pantheios.1.util
  pantheios.1.fe.simple
  pantheios.1.be.null
  pantheios.1.bec.null
  pantheios.1.inserters
  ${Log4cxx_LIBRARY}
)
add_custom_target( examples DEPENDS example.cpp.custom.wrap_log4cxx )
endif( Log4cxx_FOUND )

