#ifndef ABSTRACT_WINDOW_H
#define ABSTRACT_WINDOW_H

#pragma clang diagnostic ignored "-Wweak-vtables" //Ignore V-table warnings for abstract classes.

struct WindowConfig
{
    public:
        const char*  windowName;
        unsigned int windowType;
        int x, y;
        int width, height;
        int padding; //4 byte padding
};

class AbstractWindow
{
    public:
        static  AbstractWindow* m_window;
        virtual bool CreateWindow(WindowConfig &_conf) = 0;
        virtual bool ResetWindow (WindowConfig &_conf) = 0;
        virtual bool ResizeWindow(unsigned int _x, unsigned int _y) = 0;
        virtual void Update(float _time) = 0;
        AbstractWindow(){}


    protected:
        WindowConfig  m_configuration;
        virtual void HandleEvents() = 0;
        virtual void Render() = 0;
        virtual ~AbstractWindow(){}

};

#endif // ABSTRACT_WINDOW_H
