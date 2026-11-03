#include "MainWindow.hpp"

MainWindow::MainWindow(const wxString &title)
	:wxFrame(NULL,wxID_ANY,title){
  
}

void MainWindow::onQuit(wxCommandEvent &event){
  int answer = wxMessageBox("Confirm to quit?", "quit", wxYES_NO|wxICON_QUESTION);
  if(answer != wxYES){
	event.Skip(false);
//	event.Veto();
	return;
  }
  
}

BEGIN_EVENT_TABLE(MainWindow, wxFrame)
	EVT_MENU(wxID_EXIT, MainWindow::onQuit)
END_EVENT_TABLE()
