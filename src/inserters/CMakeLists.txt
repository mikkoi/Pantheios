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
  threadid.cpp
  w2m.cpp
)
# change w2m.cpp to m2w.cpp if you build with wide strings!
target_link_libraries( pantheios.1.inserters
  b64::b64
)

