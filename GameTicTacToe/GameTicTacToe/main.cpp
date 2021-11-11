// Game Tic Tac Toe - переводится: Игра Крестики Нолики
//
/*
   1. Создать класс родитель - TicTacToe - es
   2. Создать обработчик для класса TicTacToe - es
   3. Отдать наследование обработчика событий классу родителю - es
   4. Определить размеры окна(распределить ее геометрию) - es
   5. Составить меню -
   6. Расчертить поле игры - es
   7. Сделать функцию рисования Нолика и функцию рисования Крестика -
*/
#include "IncludedFiles.h"
#include "TicTacToe.h"

int APIENTRY wWinMain(
    _In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR lpCmdLine,
    _In_ int nCmdShow
)
{

    TicTacToe tictac;
    
    tictac.TicTacToeRegicterClass(hInstance);

    if (!tictac.TicTacToeInitInstance(hInstance, nCmdShow))
    {
        MessageBox(nullptr, L"Что-то с окном пошло не так?!", L"Error", MB_OK);
        return 0;
    }

    // Крестики
    tictac.TicTacToeInitGameButton(tictac.hButton1, 
        45, 45, 115, 115, tictac.hwnd, (HMENU)MY_BUTTON_ID_1, hInstance);
    tictac.TicTacToeInitGameButton(tictac.hButton2, 
        160, 45, 115, 115, tictac.hwnd, (HMENU)MY_BUTTON_ID_2, hInstance);
    tictac.TicTacToeInitGameButton(tictac.hButton3, 
        275, 45, 115, 115, tictac.hwnd, (HMENU)MY_BUTTON_ID_3, hInstance);
    tictac.TicTacToeInitGameButton(tictac.hButton4, 
        45, 160, 115, 115, tictac.hwnd, (HMENU)MY_BUTTON_ID_4, hInstance);
    tictac.TicTacToeInitGameButton(tictac.hButton5, 
        160, 160, 115, 115, tictac.hwnd,(HMENU)MY_BUTTON_ID_5, hInstance);
    tictac.TicTacToeInitGameButton(tictac.hButton6, 
        275, 160, 115, 115, tictac.hwnd, (HMENU)MY_BUTTON_ID_6, hInstance);
    tictac.TicTacToeInitGameButton(tictac.hButton7, 
        45, 275, 115, 115, tictac.hwnd, (HMENU)MY_BUTTON_ID_7, hInstance);
    tictac.TicTacToeInitGameButton(tictac.hButton8, 
        160, 275, 115, 115, tictac.hwnd, (HMENU)MY_BUTTON_ID_8, hInstance);
    tictac.TicTacToeInitGameButton(tictac.hButton9, 
        275, 275, 115, 115, tictac.hwnd, (HMENU)MY_BUTTON_ID_9, hInstance);
    //
    tictac.TicTacGameSign1(tictac.hButtonGame1, 420, 280, 100, 30, tictac.hwnd, (HMENU)MY_GAME_ID_1);
    tictac.TicTacGameSign2(tictac.hButtonGame2, 420, 320, 100, 30, tictac.hwnd, (HMENU)MY_GAME_ID_2);
    //
    tictac.DeleteGameButtonID(tictac.hButtonDelete,
        420, 360, 100, 30, tictac.hwnd, (HMENU)MY_DELETE_ID_10);
    //

    EventHandler eha;

    eha.WindowEventHandler();

    return eha.msg.wParam;
}