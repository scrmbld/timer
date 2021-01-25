#pragma once
#include <wx/wx.h>
#include <chrono>

class cMain : public wxFrame {
	public:
		cMain(const wxString& title);
		~cMain();
		
	public:
		bool going = false;
		std::chrono::steady_clock::time_point start_time;
		std::chrono::duration<double> time_span;

		wxStaticText *time;
		wxButton *start;
		wxButton *reset;
		
		void OnStartPressed(wxCommandEvent &evt);	
	
		wxDECLARE_EVENT_TABLE();
};
