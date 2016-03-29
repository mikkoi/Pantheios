include_directories(
  ${STLSoft_INCLUDE_DIRS}
  ${Log4CPlus_INCLUDE_DIRS}
)

if( Log4CPlus_FOUND ) # N.B. Build does not include FindLog4cxx
add_executable( example.cpp.custom.wrap_log4cplus example.cpp.custom.wrap_log4cplus.cpp )
target_link_libraries( example.cpp.custom.wrap_log4cplus
  pantheios.1.core
  pantheios.1.util
  pantheios.1.fe.simple
  pantheios.1.be.null
  pantheios.1.bec.null
  pantheios.1.inserters
  ${Log4CPlus_LIBRARY}
)
add_custom_target( examples DEPENDS example.cpp.custom.wrap_log4cplus )
endif( Log4CPlus_FOUND )

