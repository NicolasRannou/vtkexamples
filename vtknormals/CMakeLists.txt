project( normals )

cmake_minimum_required(VERSION 2.8)

find_package( VTK )

if( VTK_FOUND )
  include( ${VTK_USE_FILE} )
endif()

add_executable( normals normals.cxx
)
target_link_libraries( normals ${VTK_LIBRARIES} )

