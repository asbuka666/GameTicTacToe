#include "EventHandler.h"

BOOL EventHandler::WindowEventHandler()
{
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return TRUE;
}
