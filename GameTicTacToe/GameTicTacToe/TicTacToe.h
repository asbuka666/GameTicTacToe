#pragma once
#include "IncludedFiles.h"

class TicTacToe : public EventHandler
{
public:

	HWND hwnd;
	const wchar_t* TicTacToeClass = L"Game Tic Tac Toe Class";
	WNDCLASSEX wcx = {};

	PAINTSTRUCT ps;
	HDC hdc, hdc1, hdc2;

	HPEN hpen, hpen1, hpen2, hpen3;

	HWND  hButton, hButtonGame1, hButtonGame2;
	HWND hButton1, hButton2, hButton3,
		hButton4, hButton5, hButton6,
		hButton7, hButton8, hButton9;

	HWND hButtonDelete;

	ATOM TicTacToeRegicterClass(HINSTANCE hInstance);
	BOOL TicTacToeInitInstance(HINSTANCE hInstance, int nCmdShow);

	BOOL TicTacToeInitGameButton(HWND hButton, int x, int y, 
		int width, int height, HWND hwnd, HMENU ID_Name, HINSTANCE hInstance);

	static LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

	BOOL DeleteGameButtonID(HWND hButton, int x, int y,
		int width, int height, HWND hwnd, HMENU ID_Name);

	BOOL TicTacGameSign1(HWND hButton, int x, int y,
		int width, int height, HWND hwnd, HMENU ID_Name);

	BOOL TicTacGameSign2(HWND hButton, int x, int y,
		int width, int height, HWND hwnd, HMENU ID_Name);

	////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////
	//                           ¬ÀŒ∆≈ÕÕ€≈  À¿——€

	// –Ó·ÓÚ
	class Robot 
	{
	public:
		static BOOL Click(BOOL click);

		static int Set(int data, int size);

		static int SetR(int data, int size);

		static bool Check(int data, int size);

		static bool CheckR(int data, int size1);

		static int RandomPlayerR(int data, int size1, int size2);
	};


	class Tac// Q - X
	{
	public:

		static BOOL A(HDC hdc);
		static BOOL B(HDC hdc);
		static BOOL C(HDC hdc);
		static BOOL D(HDC hdc);
		static BOOL E(HDC hdc);
		static BOOL F(HDC hdc);
		static BOOL G(HDC hdc);
		static BOOL H(HDC hdc);
		static BOOL I(HDC hdc);
	};

	class Toe// W - 0
	{
	public:

		static BOOL A(HDC hdc);
		static BOOL B(HDC hdc);
		static BOOL C(HDC hdc);
		static BOOL D(HDC hdc);
		static BOOL E(HDC hdc);
		static BOOL F(HDC hdc);
		static BOOL G(HDC hdc);
		static BOOL H(HDC hdc);
		static BOOL I(HDC hdc);
	};
};

