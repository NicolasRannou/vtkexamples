#include <vtkSmartPointer.h>
#include <vtkCubeSource.h>
#include <vtkSphereSource.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty.h>
#include <vtkActor.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkPolyDataWriter.h>
 
int main(int, char *[])
{ 
  // 1st sphere
  vtkSmartPointer<vtkSphereSource> sphereSource = 
    vtkSmartPointer<vtkSphereSource>::New();
  vtkSmartPointer<vtkPolyDataMapper> sphereMapper = 
    vtkSmartPointer<vtkPolyDataMapper>::New();
  sphereMapper->SetInputConnection(sphereSource->GetOutputPort());
  vtkSmartPointer<vtkActor> sphereActor = 
    vtkSmartPointer<vtkActor>::New();
  sphereActor->GetProperty()->SetColor(0.5,1,0.5);
  sphereActor->GetProperty()->SetOpacity(0.5);
  sphereActor->SetMapper(sphereMapper);
   
  // 2nd sphere
  vtkSmartPointer<vtkSphereSource> sphereSource1 = 
    vtkSmartPointer<vtkSphereSource>::New();
  sphereSource1->SetCenter(0.25, 0, 0);
  sphereSource1->SetRadius(0.2);
  vtkSmartPointer<vtkPolyDataMapper> sphereMapper1 = 
    vtkSmartPointer<vtkPolyDataMapper>::New();
  sphereMapper1->SetInputConnection(sphereSource1->GetOutputPort());
  vtkSmartPointer<vtkActor> sphereActor1 = 
    vtkSmartPointer<vtkActor>::New();
  sphereActor1->GetProperty()->SetColor(1,0,0);
  sphereActor1->GetProperty()->SetOpacity(0.5);
  sphereActor1->SetMapper(sphereMapper1);
  
  // 3rd sphere
  vtkSmartPointer<vtkSphereSource> sphereSource2 = 
    vtkSmartPointer<vtkSphereSource>::New();
  sphereSource2->SetCenter(-0.25, 0, 0);
  sphereSource2->SetRadius(0.2);
  vtkSmartPointer<vtkPolyDataMapper> sphereMapper2 = 
    vtkSmartPointer<vtkPolyDataMapper>::New();
  sphereMapper2->SetInputConnection(sphereSource2->GetOutputPort());
  vtkSmartPointer<vtkActor> sphereActor2 = 
    vtkSmartPointer<vtkActor>::New();
  sphereActor2->GetProperty()->SetColor(0,1,0);
  sphereActor2->GetProperty()->SetOpacity(0.5);
  sphereActor2->SetMapper(sphereMapper2);

  // Create renderers and add actors of plane and cube
  vtkSmartPointer<vtkRenderer> renderer = 
    vtkSmartPointer<vtkRenderer>::New();
  renderer->AddActor(sphereActor);
  renderer->AddActor(sphereActor1);
  renderer->AddActor(sphereActor2);
  
  renderer->SetUseDepthPeeling(true);
//  renderer->SetOcclusionRatio(0.1);
  
  // Add renderer to renderwindow and render
  vtkSmartPointer<vtkRenderWindow> renderWindow = 
    vtkSmartPointer<vtkRenderWindow>::New();
  renderWindow->AddRenderer(renderer);
 
  vtkSmartPointer<vtkRenderWindowInteractor> interactor = 
    vtkSmartPointer<vtkRenderWindowInteractor>::New();
  interactor->SetRenderWindow(renderWindow);

  renderWindow->SetAlphaBitPlanes(1);
  renderWindow->Render();

  renderWindow->Print(cout);
  renderer->Print(cout);
 
  interactor->Start();
  return EXIT_SUCCESS;
}
