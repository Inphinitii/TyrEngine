#include <iostream>

#include "XWindow.h"
#include "LogManager.h"

using namespace std;
int main()
{
    AbstractWindow* myWindow = new XWindow();

	Log testLog = Log("TestLog.txt");

	if(testLog.Open("w"))
		testLog.Write("TESTING TEXT", Log::INFO);
	testLog.Open("w");
	testLog.Close();
	testLog.Close();

	WindowConfig conf;
    conf.height = 720;
    conf.width = 1280;
    conf.x = 1;
    conf.y = 1;
    conf.windowName = "X11 Window Test";
    if(myWindow->CreateWindow(conf))
    {
        cout << "Updating.." << endl;
        myWindow->Update(0.16f);
    }
}
