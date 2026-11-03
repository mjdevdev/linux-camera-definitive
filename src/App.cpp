#include "App.hpp"
#include "MainWindow.hpp"
#include <iostream>

bool LinuxCameraDefinitive::OnInit(){
  MainWindow *window = new MainWindow(wxT("Linux Camera Definitive")); 
  window->Show(true);
  return true;
}

IMPLEMENT_APP(LinuxCameraDefinitive);
