#include <wx/wx.h>
#include "cApp.h"
#include "cMain.h"

bool cApp::OnInit() {
	cMain *timer = new cMain(wxT("Timer"));
	timer->Show(true);
	return true;
}

wxIMPLEMENT_APP(cApp);
