#include <Windows.h>
#include "res.h"
#include <cstdlib>
#include <ctime>

INT_PTR CALLBACK DialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);
int charToInt(char ch[], int lengthChar);
int randomNumber;
HINSTANCE hInstance;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
  srand(time(NULL));
  randomNumber = rand() % 101;
  int guessNumber;
  HWND hwndMainWindow = CreateDialog(hInstance, MAKEINTRESOURCE(IDD_MAINVIEW), NULL, DialogProc);
  ShowWindow(hwndMainWindow, iCmdShow);

  MSG msg = {};
  while (GetMessage(&msg, NULL, 0, 0))
  {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }
  
  return 0;

}



INT_PTR CALLBACK DialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
  switch (uMsg)
  {

  case WM_CREATE:
    break;
  case WM_PAINT:
    HDC hDc;
    hDc = GetDC(hwndDlg);

    HBITMAP hBitMap;
    
    CHAR lpszName = "C:\Users\HP\Desktop\jab.png";
    hBitMap = LoadImage( NULL, szFileName, IMAGE_BITMAP, 0, 0,
               LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE );

    HDC hDCBitmap;
    hDCBitmap = CreateCompatibleDC(hDc);
    SelectObject(hDCBitmap, hBitMap);
    BitBlt(hDc, 0, 0, 900, 400, hDCBitmap, 0, 0, SRCCOPY);
    DeleteDC(hDCBitmap);
    DeleteObject(hBitMap);


    break;

/*
  case WM_LBUTTONUP:
    RECT okno;
    GetWindowRect(hwndDlg,&okno); // zwraca położenie okna

//    HDC hDc;
    hDc = GetDC(hwndDlg);

    BitBlt(hDc, 0, 0, 800, 600, GetDC(0), okno.left, okno.bottom, SRCCOPY);

    SelectObject(hDc, GetStockObject(ANSI_VAR_FONT));
    SetTextColor(hDc, RGB(255, 0, 0));

    TextOut(hDc, 0, 0, TEXT("Text output to client area"), 27);
    ReleaseDC(hwndDlg, hDc);
    break;

    */


  case WM_CLOSE:
    DestroyWindow(hwndDlg); // niszczenie
    PostQuitMessage(0); // umieszczenie w pętli komnuikaktoów
    return TRUE;
  }
  return FALSE;
}

int charToInt(char ch[], int lengthChar)
{
  int outInt = 0;
  if (lengthChar == 1) return ch[0] - '0';
  else
  {
    if (lengthChar == 2) return (ch[1] - '0' + (ch[0] - '0') * 10);
    else  return (ch[2] - '0' + (ch[1] - '0') * 10 + (ch[0] - '0') * 100);
  }
  return 0;
}

/*

zmodyfikuj kod aby zmiana napisu była w momencia zakocnzenia edycji tekstu

EN_CHENGE


gra :D zganij ale comp losuje


*/