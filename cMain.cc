#include <wx/wx.h>
#include <chrono>
#include <ratio>
#include "cApp.h"
#include "cMain.h"

wxBEGIN_EVENT_TABLE(cMain, wxFrame)
	EVT_BUTTON(10'002, cMain::OnStartPressed)
wxEND_EVENT_TABLE()

//TODO: find a way to update the content of wxStaticText every 0.01 seconds exactly

cMain::cMain(const wxString &title) : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(400, 300)) {
	Centre();
	
	//time display
	time = new wxStaticText(this, 10'001, wxString("Timer"), wxPoint(20, 20), wxSize(360, 130));
	time->SetLabelMarkup("<span size='40960' color='green'>timer</span>");

	//start/reset buttons
	start = new wxButton(this, 10'002, wxString("Start/Stop"), wxPoint(20, 200), wxSize(150, 40));
	reset = new wxButton(this, 10'003, wxString("Reset"), wxPoint(220, 200), wxSize(150, 40));
}

cMain::~cMain() {

}

void cMain::OnStartPressed(wxCommandEvent &evt) {
	if (going) {
		going = false;
		//stop the timer
		time_span = std::chrono::duration_cast<std::chrono::duration<double>>(std::chrono::steady_clock::now() - start_time);
		time->SetLabelMarkup("<span size='40960' color='green'>" + std::to_string(time_span.count()) + "</span>");
	} else {
		going = true;
		//start the timer
		start_time = std::chrono::steady_clock::now();
	}

	evt.Skip();
}
