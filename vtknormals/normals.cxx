#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>

#include "vtkPolyData.h"
#include "vtkPolyDataReader.h"
#include "vtkPolyDataWriter.h"
#include "vtkPolyDataNormals.h"
#include "vtkSmartPointer.h"
#include "vtkTriangleFilter.h"

int main ( int argc, char* argv[] )
{
  if ( argc < 2 )
  {
    std::cerr << "Usage: " << std::endl;
    std::cerr << argv[0] << " mesh.vtk" << std::endl;
    return EXIT_FAILURE;
  }

  // read polydata
  vtkSmartPointer<vtkPolyDataReader> reader =
    vtkSmartPointer<vtkPolyDataReader>::New();
  reader->SetFileName( argv[1] );
  reader->Update();

  vtkSmartPointer<vtkTriangleFilter> triangle =
    vtkSmartPointer<vtkTriangleFilter>::New();
  triangle->SetInput(reader->GetOutput());
  triangle->Update();

  std::cout << "triangles!" << std::endl;
  
  // compute normals
  vtkSmartPointer<vtkPolyDataNormals> normals =
    vtkSmartPointer<vtkPolyDataNormals>::New();
  normals->SetInput(triangle->GetOutput());
  normals->SetFeatureAngle(60);
  normals->ComputePointNormalsOn();
  normals->NonManifoldTraversalOn();
  normals->ConsistencyOn();
//  normals->FlipNormalsOn();
  normals->Update();

  // char* to string
  std::string path = argv[1];
  // extract file name (DOESNT WORK ON WINDOWS)
  size_t found = path.find_last_of("/");
  // remove path
  std::string filename = path.substr(found+1);

  // write polydata
  vtkSmartPointer<vtkPolyDataWriter> writer =
    vtkSmartPointer<vtkPolyDataWriter>::New();
  writer->SetInput( normals->GetOutput() );
  writer->SetFileName( filename.c_str() );
  writer->Write();

  return EXIT_SUCCESS;
}
