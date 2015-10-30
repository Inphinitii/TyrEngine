#ifndef XWINDOW_H
#define XWINDOW_H

#include "AbstractWindow.h"
#include <X11/Xlib.h>

//Window type:1

class XWindow : public AbstractWindow
{
    public:
        //CREATE A GETTER FOR THE CONF FILE
        bool CreateWindow(WindowConfig &_conf);
        bool ResetWindow (WindowConfig &_conf);
        bool ResizeWindow(unsigned int _x, unsigned int _y);
        void Update(float _time);
        XWindow();

        Display* GetDisplay() { return m_display; }
        Window   GetWindow() { return m_currentWindow; }

    private:
        int 				m_screen; //Store the DefaultScreen as an integer.
		long              m_eventMask;
        GC            		m_graphicContext;
        Display*  	m_display;
        Window    	m_rootWindow; //The root window of the system.
        Window   	m_currentWindow;
        Colormap	m_colorMap; //The color map of the display.
        XEvent       	m_event;

        XWindowChanges m_changes;
        ~XWindow();

    protected:
        void Render();
        void HandleEvents();
};

#endif // XWINDOW_H
