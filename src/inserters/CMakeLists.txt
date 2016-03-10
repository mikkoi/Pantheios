include_directories(
  ${STLSoft_INCLUDE_DIRS}
  ${b64_INCLUDE_DIRS}
)

add_library( pantheios.1.inserters
  args.cpp
  b64.cpp
  blob.cpp
  boolean.cpp
  exception.cpp
  hostid.cpp
  integer.cpp
  pointer.cpp
  processid.cpp
  real.cpp
  slice.cpp
  stream_character.cpp
  threadid.cpp
  w2m.cpp
)
# change w2m.cpp to m2w.cpp if you build with wide strings!
target_link_libraries( pantheios.1.inserters
  pantheios.1.util
  b64::b64
)

add_library( pantheios.1.inserters.w2m
  args.cpp
  b64.cpp
  blob.cpp
  boolean.cpp
  exception.cpp
  hostid.cpp
  integer.cpp
  pointer.cpp
  processid.cpp
  real.cpp
  slice.cpp
  stream_character.cpp
  threadid.cpp
  w2m.cpp
)
target_link_libraries( pantheios.1.inserters.w2m
  b64::b64
)

# set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DPANTHEIOS_USE_WIDE_STRINGS")
add_library( pantheios.1.inserters.m2w
  args.cpp
  b64.cpp
  blob.cpp
  boolean.cpp
  exception.cpp
  hostid.cpp
  integer.cpp
  pointer.cpp
  processid.cpp
  real.cpp
  slice.cpp
  # stream_character.cpp
  threadid.cpp
  # m2w.cpp
)
# change w2m.cpp to m2w.cpp if you build with wide strings!
target_link_libraries( pantheios.1.inserters.m2w
  b64::b64
)

# TODO Wait for fix in GCC, maybe!
# set_target_properties( pantheios.1.inserters.m2w
#   PROPERTIES COMPILE_DEFINITIONS PANTHEIOS_USE_WIDE_STRINGS
# )

