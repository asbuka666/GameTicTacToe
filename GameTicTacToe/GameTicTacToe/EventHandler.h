#pragma once
#include "IncludedFiles.h"

//class TicTacToe;

class EventHandler 
{
public:
	EventHandler() {}
	MSG msg;
	BOOL WindowEventHandler();
};