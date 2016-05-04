#ifndef SUBBUFFERPANEL_H
#define SUBBUFFERPANEL_H

#include <wx/wx.h>

#include "xlCustomControl.h"

class SubBufferPanel : public wxWindow, public xlCustomControl
{
    public:
        SubBufferPanel(wxPanel* parent, wxWindowID id, const wxPoint &pos=wxDefaultPosition,
                       const wxSize &size=wxDefaultSize, long style=0);
        virtual ~SubBufferPanel();

        virtual void SetValue(const std::string &val) override;
        std::string GetValue();
        void SetDefaults();
    protected:
        DECLARE_EVENT_TABLE()

    
        void mouseLeftDown( wxMouseEvent& event);
        void mouseLeftUp( wxMouseEvent& event);
        void mouseMoved( wxMouseEvent& event);
        void Paint( wxPaintEvent& event );

    private:
        int OverMouseHandle(wxMouseEvent& event);
        void Convert(float &x, float &y, wxMouseEvent& event);
    
        float x1, y1, x2, y2;
    
        int draggingHandle;
    
};

#endif // SUBBUFFERPANEL_H
