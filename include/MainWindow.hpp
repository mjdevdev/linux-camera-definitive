#include "wx/wx.h"

class MainWindow : public wxFrame {
  public:
	MainWindow(const wxString &title);
	void onQuit(wxCommandEvent &event);

  private:
	DECLARE_EVENT_TABLE()
};
