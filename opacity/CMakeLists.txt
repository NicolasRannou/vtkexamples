cmake_minimum_required(VERSION 2.6)
 
PROJECT(Opacity)
 
FIND_PACKAGE(VTK REQUIRED)
INCLUDE(${VTK_USE_FILE})
 
ADD_EXECUTABLE(Opacity Opacity.cxx)
TARGET_LINK_LIBRARIES(Opacity vtkHybrid)
