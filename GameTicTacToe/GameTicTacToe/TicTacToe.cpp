#include "TicTacToe.h"

static int arr[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
static int tru[18] = { 0 };
static int arrR[9] = { 0 };

ATOM TicTacToe::TicTacToeRegicterClass(HINSTANCE hInstance)
{
	wcx.cbSize = sizeof(wcx);
	wcx.lpszClassName = TicTacToeClass;
	wcx.lpszMenuName = NULL;
	wcx.lpfnWndProc = WndProc;
	wcx.cbWndExtra = NULL;
	wcx.cbClsExtra = NULL;
	wcx.hIcon = LoadIcon(nullptr, IDI_WINLOGO);
	wcx.hCursor = LoadCursor(nullptr, IDI_WINLOGO);
	wcx.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wcx.hInstance = hInstance;

	return RegisterClassEx(&wcx);
}

BOOL TicTacToe::TicTacToeInitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hwnd = CreateWindowEx(
		WS_EX_CLIENTEDGE | WS_EX_WINDOWEDGE,
		TicTacToeClass,
		L"Игра: крестики - нолики",
		WS_OVERLAPPED | WS_BORDER | WS_SYSMENU,//WS_OVERLAPPED | WS_SIZEBOX | WS_BORDER | WS_SYSMENU,
		CW_USEDEFAULT, CW_USEDEFAULT,
		580, 480,
		nullptr, nullptr,
		hInstance, nullptr
	);

	if (!hwnd)
	{
		return FALSE;
	}

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	return TRUE;
}

BOOL TicTacToe::TicTacToeInitGameButton(
	HWND hButton, int x, int y, int width, 
	int height, HWND hwnd, HMENU ID_Name, HINSTANCE hInstance)
{
	TicTacToe tictac;
	hButton = CreateWindowEx(
		0,
		L"BUTTON",
		L"",
		WS_VISIBLE | WS_CHILD,
		x, y, width, height,// 45, 45, 115, 115,
		hwnd,
		ID_Name,
		HINSTANCE(hInstance), nullptr
	);

	if (!hButton)
	{
		return FALSE;
	}

	return TRUE;
}

BOOL TicTacToe::DeleteGameButtonID(
	HWND hButton, int x, int y, int width,
	int height, HWND hwnd, HMENU ID_Name)
{
	TicTacToe tictac;
	hButton = CreateWindowEx(
		NULL,
		L"BUTTON",
		L"Выход",
		WS_VISIBLE | WS_CHILD,
		x, y, width, height,
		hwnd,
		ID_Name,
		NULL, NULL
	);

	if (!hButton)
	{
		return FALSE;
	}

	return TRUE;
}

BOOL TicTacToe::TicTacGameSign1(
	HWND hButton, int x, int y, int width,
	int height, HWND hwnd, HMENU ID_Name)
{
	TicTacToe tictac;
	hButton = CreateWindowEx(
		NULL,
		L"BUTTON",
		L"Выбор - Х",
		WS_VISIBLE | WS_CHILD,
		x, y, width, height,
		hwnd,
		ID_Name,
		NULL, NULL
	);

	if (!hButton)
	{
		return FALSE;
	}

	return TRUE;
}

BOOL TicTacToe::TicTacGameSign2(
	HWND hButton, int x, int y, int width,
	int height, HWND hwnd, HMENU ID_Name)
{
	TicTacToe tictac;
	hButton = CreateWindowEx(
		NULL,
		L"BUTTON",
		L"Выбор - 0",
		WS_VISIBLE | WS_CHILD,
		x, y, width, height,
		hwnd,
		ID_Name,
		NULL, NULL
	);

	if (!hButton)
	{
		return FALSE;
	}

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////

LRESULT TicTacToe::WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	// Классы -------- +
	TicTacToe tictac;
	//---------------- +

	//static int tru[18] = { 0 };

	static int sx, sy, chis;
	int x = 0, y = 0;

	// С этой еще пока не известно?!
	static String str;
	static BOOL q = FALSE, w = FALSE, max_rob1 = FALSE, max_rob2 = FALSE;

	
	switch (message)
	{
	case WM_CREATE:
		break;

	case WM_CHAR:
		str += (TCHAR)wParam;
		InvalidateRect(hwnd, NULL, TRUE);
		break;

	case WM_COMMAND:
		tictac.hdc1 = GetDC(hwnd);
		tictac.hpen1 = CreatePen(PS_SOLID, 4, RGB(255, 0, 0));
		SelectObject(tictac.hdc1, tictac.hpen1);

		tictac.hdc2 = GetDC(hwnd);
		tictac.hpen2 = CreatePen(PS_SOLID, 6, RGB(0, 0, 255));
		SelectObject(tictac.hdc2, tictac.hpen2);


		if (wParam == 701)
		{
			q = TRUE;
			max_rob1 = TRUE;
		}

		if (wParam == 702)
		{
			w = TRUE;
			max_rob2 = TRUE;
		}

		/*if (wParam == 703)
		{
			max_rob = TRUE;
		}*/

		////////////////////////////////////////////////////////

		//BM_CLICK;
		//BN_HILITE;
		//BN_DISABLE;
		//BN_CLICKED;// Это флаг для клика без клика.

		////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


		for (int i = 0; i < 9; i++)// x q w
		{
			if (max_rob1 == TRUE)
			{
				chis = TicTacToe::Robot::RandomPlayerR(9, 0, 9);
				wParam = chis + 600;
			}
			// Q
			if (max_rob1 || q)
			{
				switch (wParam)
				{
				case 601:// A
					if(TicTacToe::Robot::Check(1, 1))
					{
						TicTacToe::Robot::Set(1, 10);
						tru[0] = 1;
						//
						w = TRUE;
						q = FALSE;
						max_rob1 = FALSE;

						break;
					}

					break;

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
				//                B

				case 602:// B
					if (TicTacToe::Robot::Check(2, 2))
					{
						TicTacToe::Robot::Set(2, 20);
						tru[1] = 2;
						//
						w = TRUE;
						q = FALSE;
						max_rob1 = FALSE;

						break;
					}

					break;

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
					//                C

				case 603:// C
					if (TicTacToe::Robot::Check(3, 3))
					{
						TicTacToe::Robot::Set(3, 30);
						tru[2] = 3;
						//
						w = TRUE;
						q = FALSE;
						max_rob1 = FALSE;

						break;
					}

					break;

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
					//                D

				case 604:// D
					if (TicTacToe::Robot::Check(4, 4))
					{
						TicTacToe::Robot::Set(4, 40);
						tru[3] = 4;
						//
						w = TRUE;
						q = FALSE;
						max_rob1 = FALSE;

						break;
					}

					break;

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
					//                E

				case 605:// E
					if (TicTacToe::Robot::Check(5, 5))
					{
						TicTacToe::Robot::Set(5, 50);
						tru[4] = 5;
						//
						w = TRUE;
						q = FALSE;
						max_rob1 = FALSE;

						break;
					}

					break;

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
					//                F

				case 606:// F
					if (TicTacToe::Robot::Check(6, 6))
					{
						TicTacToe::Robot::Set(6, 60);
						tru[5] = 6;
						//
						w = TRUE;
						q = FALSE;
						max_rob1 = FALSE;

						break;
					}

					break;

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
					//                G

				case 607:// G
					if (TicTacToe::Robot::Check(7, 7))
					{
						TicTacToe::Robot::Set(7, 70);
						tru[6] = 7;
						//
						w = TRUE;
						q = FALSE;
						max_rob1 = FALSE;

						break;
					}

					break;

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
					//                H

				case 608:// H
					if (TicTacToe::Robot::Check(8, 8))
					{
						TicTacToe::Robot::Set(8, 80);
						tru[7] = 8;
						//
						w = TRUE;
						q = FALSE;
						max_rob1 = FALSE;

						break;
					}

					break;

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
					//                I

				case 609:// I
					if (TicTacToe::Robot::Check(9, 9))
					{
						TicTacToe::Robot::Set(9, 90);
						tru[8] = 9;
						//
						w = TRUE;
						q = FALSE;
						max_rob1 = FALSE;

						break;
					}

					break;
				}
			}


/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

                               // W - 0


			if (max_rob2 || w)
			{
				switch (wParam)
				{
				case 601:// A
					if (TicTacToe::Robot::Check(1, 1))
					{
						TicTacToe::Robot::Set(1, 10);
						TicTacToe::Robot::SetR(1, 1);
						tru[9] = 10;
						//
						q = TRUE;
						w = FALSE;
						max_rob1 = TRUE;

						break;
					}

					break;

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
					//                B

				case 602:// B
					if (TicTacToe::Robot::Check(2, 2))
					{
						TicTacToe::Robot::Set(2, 20);
						TicTacToe::Robot::SetR(2, 2);
						tru[10] = 11;
						//
						q = TRUE;
						w = FALSE;
						max_rob1 = TRUE;

						break;
					}

					break;

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
					//                C

				case 603:// C
					if (TicTacToe::Robot::Check(3, 3))
					{
						TicTacToe::Robot::Set(3, 30);
						TicTacToe::Robot::SetR(3, 3);
						tru[11] = 12;
						//
						q = TRUE;
						w = FALSE;
						max_rob1 = TRUE;

						break;
					}

					break;

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
					//                D

				case 604:// D
					if (TicTacToe::Robot::Check(4, 4))
					{
						TicTacToe::Robot::Set(4, 40);
						TicTacToe::Robot::SetR(4, 4);
						tru[12] = 13;
						//
						q = TRUE;
						w = FALSE;
						max_rob1 = TRUE;

						break;
					}

					break;

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
					//                E

				case 605:// E
					if (TicTacToe::Robot::Check(5, 5))
					{
						TicTacToe::Robot::Set(5, 50);
						TicTacToe::Robot::SetR(5, 5);
						tru[13] = 14;
						//
						q = TRUE;
						w = FALSE;
						max_rob1 = TRUE;

						break;
					}

					break;

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
					//                F

				case 606:// F
					if (TicTacToe::Robot::Check(6, 6))
					{
						TicTacToe::Robot::Set(6, 60);
						TicTacToe::Robot::SetR(6, 6);
						tru[14] = 15;
						//
						q = TRUE;
						w = FALSE;
						max_rob1 = TRUE;

						break;
					}

					break;

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
					//                G

				case 607:// G
					if (TicTacToe::Robot::Check(7, 7))
					{
						TicTacToe::Robot::Set(7, 70);
						TicTacToe::Robot::SetR(7, 7);
						tru[15] = 16;
						//
						q = TRUE;
						w = FALSE;
						max_rob1 = TRUE;

						break;
					}

					break;

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
					//                H

				case 608:// H
					if (TicTacToe::Robot::Check(8, 8))
					{
						TicTacToe::Robot::Set(8, 80);
						TicTacToe::Robot::SetR(8, 8);
						tru[16] = 17;
						//
						q = TRUE;
						w = FALSE;
						max_rob1 = TRUE;

						break;
					}

					break;

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
					//                I

				case 609:// I
					if (TicTacToe::Robot::Check(9, 9))
					{
						TicTacToe::Robot::Set(9, 90);
						TicTacToe::Robot::SetR(9, 9);
						tru[17] = 18;
						//
						q = TRUE;
						w = FALSE;
						max_rob1 = TRUE;

						break;
					}

					break;
				}
			}

/////////////////////////////////////////////////////////////////////////////

			//.............................................................
				//	//BM_CLICK;
				//	//BN_HILITE;
				//	//BN_DISABLE;
				//	//BN_CLICKED;// Эти флаги, по ходу, для клика без клика.
			//..............................................................
			//                Расклад - Х

			if (tru[0] == 1)
			{
				TicTacToe::Tac::A(tictac.hdc1);
			}
			if (tru[1] == 2)
			{
				TicTacToe::Tac::B(tictac.hdc1);
			}
			if (tru[2] == 3)
			{
				TicTacToe::Tac::C(tictac.hdc1);
			}
			if (tru[3] == 4)
			{
				TicTacToe::Tac::D(tictac.hdc1);
			}
			if (tru[4] == 5)
			{
				TicTacToe::Tac::E(tictac.hdc1);
			}
			if (tru[5] == 6)
			{
				TicTacToe::Tac::F(tictac.hdc1);
			}
			if (tru[6] == 7)
			{
				TicTacToe::Tac::G(tictac.hdc1);
			}
			if (tru[7] == 8)
			{
				TicTacToe::Tac::H(tictac.hdc1);
			}
			if (tru[8] == 9)
			{
				TicTacToe::Tac::I(tictac.hdc1);
			}

			///////////////////////////////////////////////////////
			//                Расклад - 0

			if (tru[9] == 10)
			{
				TicTacToe::Toe::A(tictac.hdc2);
			}
			if (tru[10] == 11)
			{
				TicTacToe::Toe::B(tictac.hdc2);
			}
			if (tru[11] == 12)
			{
				TicTacToe::Toe::C(tictac.hdc2);
			}
			if (tru[12] == 13)
			{
				TicTacToe::Toe::D(tictac.hdc2);
			}
			if (tru[13] == 14)
			{
				TicTacToe::Toe::E(tictac.hdc2);
			}
			if (tru[14] == 15)
			{
				TicTacToe::Toe::F(tictac.hdc2);
			}
			if (tru[15] == 16)
			{
				TicTacToe::Toe::G(tictac.hdc2);
			}
			if (tru[16] == 17)
			{
				TicTacToe::Toe::H(tictac.hdc2);
			}
			if (tru[17] == 18)
			{
				TicTacToe::Toe::I(tictac.hdc2);
			}
		}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
			//              ВЫХОД

		if (wParam == MY_DELETE_ID_10)
		{

			q = FALSE;
			w = FALSE;

			max_rob1 = FALSE;
			max_rob2 = FALSE;

			InvalidateRect(hwnd, NULL, TRUE);

			for (int i = 0; i < 9; i++)
				arr[i] = i + 1;

			for (int i = 0; i < 9; i++)
				arrR[i] = 0;

			for (int i = 0; i < 18; i++)
				tru[i] = 0;

			ReleaseDC(hwnd, tictac.hdc1);
			ReleaseDC(hwnd, tictac.hdc2);
			DeleteObject(tictac.hpen);
		}
		//
		
		break;

////////////////////////////////////////////////////////////////////////////////

	case WM_SIZE:
		sx = LOWORD(lParam);
		sy = HIWORD(lParam);
		break;

	case WM_PAINT:
		tictac.hdc = BeginPaint(hwnd, &tictac.ps);
		//
		
		//
		EndPaint(hwnd, &tictac.ps);
		break;

	case WM_DESTROY:
		DeleteObject(tictac.hpen);
		ReleaseDC(hwnd, tictac.hdc1);
		ReleaseDC(hwnd, tictac.hdc2);
		PostQuitMessage(0);
		break;

	default: return DefWindowProc(hwnd, message, wParam, lParam);
	}

	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////




/////////////////////////////////////////////////////////////////////////////////////////
//
//                                       W - 0
//
/////////////////////////////////////////////////////////////////////////////////////////

BOOL TicTacToe::Toe::A(HDC hdc)
{
	Ellipse(hdc, 70, 55, 125, 140);

	return TRUE;
}

BOOL TicTacToe::Toe::B(HDC hdc)
{
	Ellipse(hdc, 190, 55, 245, 140);

	return TRUE;
}

BOOL TicTacToe::Toe::C(HDC hdc)
{
	Ellipse(hdc, 305, 55, 360, 140);

	return TRUE;
}

BOOL TicTacToe::Toe::D(HDC hdc)
{
	Ellipse(hdc, 70, 175, 125, 260);

	return TRUE;
}

BOOL TicTacToe::Toe::E(HDC hdc)
{
	Ellipse(hdc, 190, 175, 245, 260);

	return TRUE;
}

BOOL TicTacToe::Toe::F(HDC hdc)
{
	Ellipse(hdc, 305, 175, 360, 260);

	return TRUE;
}

BOOL TicTacToe::Toe::G(HDC hdc)
{
	Ellipse(hdc, 70, 290, 125, 375);

	return TRUE;
}

BOOL TicTacToe::Toe::H(HDC hdc)
{
	Ellipse(hdc, 190, 290, 245, 375);

	return TRUE;
}

BOOL TicTacToe::Toe::I(HDC hdc)
{
	Ellipse(hdc, 305, 290, 360, 375);

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                       Q - X
//
/////////////////////////////////////////////////////////////////////////////////////////

BOOL TicTacToe::Tac::A(HDC hdc)
{
	MoveToEx(hdc, 55, 55, NULL);
	LineTo(hdc, 140, 140);

	MoveToEx(hdc, 55, 140, NULL);
	LineTo(hdc, 140, 55);

	return TRUE;
}

BOOL TicTacToe::Tac::B(HDC hdc)
{
	MoveToEx(hdc, 175, 55, NULL);
	LineTo(hdc, 260, 140);

	MoveToEx(hdc, 260, 55, NULL);
	LineTo(hdc, 175, 140);

	return TRUE;
}

BOOL TicTacToe::Tac::C(HDC hdc)
{
	MoveToEx(hdc, 290, 55, NULL);
	LineTo(hdc, 375, 140);

	MoveToEx(hdc, 290, 140, NULL);
	LineTo(hdc, 375, 55);

	return TRUE;
}

BOOL TicTacToe::Tac::D(HDC hdc)
{
	MoveToEx(hdc, 55, 175, NULL);
	LineTo(hdc, 140, 260);

	MoveToEx(hdc, 55, 260, NULL);
	LineTo(hdc, 140, 175);

	return TRUE;
}

BOOL TicTacToe::Tac::E(HDC hdc)
{
	MoveToEx(hdc, 175, 175, NULL);
	LineTo(hdc, 260, 260);

	MoveToEx(hdc, 260, 175, NULL);
	LineTo(hdc, 175, 260);

	return TRUE;
}

BOOL TicTacToe::Tac::F(HDC hdc)
{
	MoveToEx(hdc, 290, 175, NULL);
	LineTo(hdc, 375, 260);

	MoveToEx(hdc, 290, 260, NULL);
	LineTo(hdc, 375, 175);

	return TRUE;
}

BOOL TicTacToe::Tac::G(HDC hdc)
{
	MoveToEx(hdc, 55, 290, NULL);
	LineTo(hdc, 140, 375);

	MoveToEx(hdc, 55, 375, NULL);
	LineTo(hdc, 140, 290);

	return TRUE;
}

BOOL TicTacToe::Tac::H(HDC hdc)
{
	MoveToEx(hdc, 175, 290, NULL);
	LineTo(hdc, 260, 375);

	MoveToEx(hdc, 260, 290, NULL);
	LineTo(hdc, 175, 375);

	return TRUE;
}

BOOL TicTacToe::Tac::I(HDC hdc)
{
	MoveToEx(hdc, 290, 290, NULL);
	LineTo(hdc, 375, 375);

	MoveToEx(hdc, 290, 375, NULL);
	LineTo(hdc, 375, 290);

	return TRUE;
}




/////////////////////////////////////////////////////////////////////////////////////////
//
//                                     РОБОТ
//
/////////////////////////////////////////////////////////////////////////////////////////

BOOL TicTacToe::Robot::Click(BOOL click)
{
	switch (click)
	{
	case 0: return click = 1; break;
	case 1: return click = 0; break;
	}
}

int TicTacToe::Robot::Set(int data, int size)
{
		switch (data - 1)
		{
		case 0: arr[0] = size; break;
		case 1: arr[1] = size; break;
		case 2: arr[2] = size; break;
		case 3: arr[3] = size; break;
		case 4: arr[4] = size; break;
		case 5: arr[5] = size; break;
		case 6: arr[6] = size; break;
		case 7: arr[7] = size; break;
		case 8: arr[8] = size; break;
		}
	
		return *arr;
}

int TicTacToe::Robot::SetR(int data, int size)
{
	switch (data - 1)
	{
	case 0: arrR[0] = size; break;
	case 1: arrR[1] = size; break;
	case 2: arrR[2] = size; break;
	case 3: arrR[3] = size; break;
	case 4: arrR[4] = size; break;
	case 5: arrR[5] = size; break;
	case 6: arrR[6] = size; break;
	case 7: arrR[7] = size; break;
	case 8: arrR[8] = size; break;
	}

	return *arrR;
}

bool TicTacToe::Robot::Check(int data, int size)
{
	while (true)
	{
		switch (data - 1)
		{
		case 0:
			if (arr[0] == size)
				return true;
			else return false;
		case 1:
			if (arr[1] == size)
				return true;
			else return false;
		case 2:
			if (arr[2] == size)
				return true;
			else return false;
		case 3:
			if (arr[3] == size)
				return true;
			else return false;
		case 4:
			if (arr[4] == size)
				return true;
			else return false;
		case 5:
			if (arr[5] == size)
				return true;
			else return false;
		case 6:
			if (arr[6] == size)
				return true;
			else return false;
		case 7:
			if (arr[7] == size)
				return true;
			else return false;
		case 8:
			if (arr[8] == size)
				return true;
			else return false;
		}

		data--;
	}

	return 0;
}

bool TicTacToe::Robot::CheckR(int data, int size)
{
	while (true)
	{
		switch (data - 1)
		{
		case 0:
			if (arrR[0] == size)
				return true;
			else return false;
		case 1:
			if (arrR[1] == size)
				return true;
			else break;
		case 2:
			if (arrR[2] == size)
				return true;
			else break;
		case 3:
			if (arrR[3] == size)
				return true;
			else break;
		case 4:
			if (arrR[4] == size)
				return true;
			else break;
		case 5:
			if (arrR[5] == size)
				return true;
			else break;
		case 6:
			if (arrR[6] == size)
				return true;
			else break;
		case 7:
			if (arrR[7] == size)
				return true;
			else break;
		case 8:
			if (arrR[8] == size)
				return true;
			else break;
		}

		data--;
	}

	return false;
}

int TicTacToe::Robot::RandomPlayerR(int data, int size1, int size2)
{
	srand((unsigned int)time(NULL));

	static int t1;
	static int size_a = data;
	
	if (size_a == 0 || data == 0)
		size_a = 1;

	if (size_a < 1)
		size_a = data;

	switch (size_a)
	{
	case 1:
		if (data == 1)
		{
			t1 = size1 + rand() % size2 + 1;
			TicTacToe::Robot::SetR(t1, t1); size_a--; return t1;
		}
		while (TicTacToe::Robot::CheckR(data, t1))
			t1 = size1 + rand() % size2 + 1;
		TicTacToe::Robot::SetR(t1, t1);size_a--; return t1;

	case 2:
		if (data == 2)
		{
			t1 = size1 + rand() % size2 + 1;
			TicTacToe::Robot::SetR(t1, t1); size_a--; return t1;
		}
		while (TicTacToe::Robot::CheckR(data, t1))
			t1 = size1 + rand() % size2 + 1;
		TicTacToe::Robot::SetR(t1, t1); size_a--; return t1;

	case 3:
		if (data == 3)
		{
			t1 = size1 + rand() % size2 + 1;
			TicTacToe::Robot::SetR(t1, t1); size_a--; return t1;
		}
		while (TicTacToe::Robot::CheckR(data, t1))
			t1 = size1 + rand() % size2 + 1;
		TicTacToe::Robot::SetR(t1, t1); size_a--; return t1;

	case 4:
		if (data == 4)
		{
			t1 = size1 + rand() % size2 + 1;
			TicTacToe::Robot::SetR(t1, t1); size_a--; return t1;
		}
		while (TicTacToe::Robot::CheckR(data, t1))
			t1 = size1 + rand() % size2 + 1;
		TicTacToe::Robot::SetR(t1, t1); size_a--; return t1;

	case 5:
		if (data == 5)
		{
			t1 = size1 + rand() % size2 + 1;
			TicTacToe::Robot::SetR(t1, t1); size_a--; return t1;
		}
		while (TicTacToe::Robot::CheckR(data, t1))
			t1 = size1 + rand() % size2 + 1;
		TicTacToe::Robot::SetR(t1, t1); size_a--; return t1;

	case 6:
		if (data == 6)
		{
			t1 = size1 + rand() % size2 + 1;
			TicTacToe::Robot::SetR(t1, t1); size_a--; return t1;
		}
		while (TicTacToe::Robot::CheckR(data, t1))
			t1 = size1 + rand() % size2 + 1;
		TicTacToe::Robot::SetR(t1, t1); size_a--; return t1;

	case 7:
		if (data == 7)
		{
			t1 = size1 + rand() % size2 + 1;
			TicTacToe::Robot::SetR(t1, t1); size_a--; return t1;
		}
		while (TicTacToe::Robot::CheckR(data, t1))
			t1 = size1 + rand() % size2 + 1;
		TicTacToe::Robot::SetR(t1, t1); size_a--; return t1;

	case 8:
		if (data == 8)
		{
			t1 = size1 + rand() % size2 + 1;
			TicTacToe::Robot::SetR(t1, t1); size_a--; return t1;
		}
		while (TicTacToe::Robot::CheckR(data, t1))
			t1 = size1 + rand() % size2 + 1;
		TicTacToe::Robot::SetR(t1, t1); size_a--; return t1;

	case 9:
		if (data == 9)
		{
			t1 = size1 + rand() % size2 + 1;
			TicTacToe::Robot::SetR(t1, t1); size_a--; return t1;
		}
		while (TicTacToe::Robot::CheckR(data, t1))
			t1 = size1 + rand() % size2 + 1;
		TicTacToe::Robot::SetR(t1, t1); size_a--; return t1;
	}

	return t1;
}
