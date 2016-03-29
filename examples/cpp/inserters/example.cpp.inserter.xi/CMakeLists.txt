include_directories(
  ${STLSoft_INCLUDE_DIRS}
)

add_executable( example.cpp.inserter.xi example.cpp.inserter.xi.cpp )
target_link_libraries( example.cpp.inserter.xi
  pantheios.1.core
  pantheios.1.util
  pantheios.1.fe.simple
  pantheios.1.be.null
  pantheios.1.bec.null
  pantheios.1.inserters
)
add_custom_target( examples DEPENDS example.cpp.inserter.xi )

