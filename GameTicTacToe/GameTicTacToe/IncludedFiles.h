#pragma once

#include <Windows.h>
#include <tchar.h>
#include <iostream>
#include <hstring.h>
#include <windowsx.h>
#include <string>
#include <stdio.h>
#include <CommCtrl.h>
#include <ctime>
//
#include <time.h>
#include <ctime>
//#include "TicTacToe.h" ��� �� �� ��������� ������ 2504 (�� ��������� ������� �����)
// ���� ������� ��� ��� �� ������� ����� �� ��� ��������� ����� ����������, �� ����... .
#include "EventHandler.h"

// ���������� ���������� basic_string ������� ����� �������� � ��������� ���� TCHAR
typedef std::basic_string<TCHAR, std::char_traits<TCHAR>, std::allocator<TCHAR>>String;

// ��� ����
#define FILE_MENU_NEW 10
#define FILE_MENU_OPEN 11
#define FILE_MENU_LOOK 12
#define FILE_MENU_CLOSE 13
#define FILE_MY_MENU_NEW 14
#define FILE_MY_MENU_OPEN 15
#define FILE_MY_MENU_LOOK 16
#define OPEN_TASKS 17
#define LOOK_TASKS 18
#define CUTOUT_TASKS 19

// ������� ������
#define MY_BUTTON_ID_1 601
#define MY_BUTTON_ID_2 602
#define MY_BUTTON_ID_3 603
#define MY_BUTTON_ID_4 604
#define MY_BUTTON_ID_5 605
#define MY_BUTTON_ID_6 606
#define MY_BUTTON_ID_7 607
#define MY_BUTTON_ID_8 608
#define MY_BUTTON_ID_9 609
//---
//#define MY_BUTTON_ID_11 611
//#define MY_BUTTON_ID_12 612
//#define MY_BUTTON_ID_13 613
//#define MY_BUTTON_ID_14 614
//#define MY_BUTTON_ID_15 615
//#define MY_BUTTON_ID_16 616
//#define MY_BUTTON_ID_17 617
//#define MY_BUTTON_ID_18 618
//#define MY_BUTTON_ID_19 619
//
//#define MY_BUTTON_ID_21 621
//#define MY_BUTTON_ID_22 622
//#define MY_BUTTON_ID_23 623
//#define MY_BUTTON_ID_24 624
//#define MY_BUTTON_ID_25 625
//#define MY_BUTTON_ID_26 626
//#define MY_BUTTON_ID_27 627
//#define MY_BUTTON_ID_28 628
//#define MY_BUTTON_ID_29 629
//---

// ��� ������ - ���������
#define BTN_MYBUTTON_ID_1 503

// ��� ������� ���� ���������
#define MY_DELETE_ID_10 510

// ����� �������� ������
#define MY_GAME_ID_1 701 // ������� 
#define MY_GAME_ID_2 702// ����
#define MY_GAME_ID_3 703// �����


