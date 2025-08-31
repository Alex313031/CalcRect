#ifndef CALCRECT_H_
#define CALCRECT_H_

#include <windows.h>
#include <windowsx.h>
#include <commctrl.h>
#include <tchar.h>

#if _WIN32_WINNT <= 0x0501

extern "C" {
WINBASEAPI BOOL WINAPI
SetDllDirectoryA(
    __in_opt LPCSTR lpPathName);

WINBASEAPI BOOL WINAPI
SetDllDirectoryW(
    __in_opt LPCWSTR lpPathName);

WINBASEAPI DWORD WINAPI
GetDllDirectoryA(
    __in DWORD nBufferLength,
    __out_ecount_part_opt(nBufferLength, return + 1) LPSTR lpBuffer);

WINBASEAPI DWORD WINAPI
GetDllDirectoryW(
    __in DWORD nBufferLength,
    __out_ecount_part_opt(nBufferLength, return + 1) LPWSTR lpBuffer);
}

#ifdef UNICODE
 #define SetDllDirectory  SetDllDirectoryW
 #define GetDllDirectory  GetDllDirectoryW
#else
 #define SetDllDirectory  SetDllDirectoryA
 #define GetDllDirectory  GetDllDirectoryA
#endif // UNICODE

#endif // _WIN32_WINNT <= 0x0501

BOOL OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam);
void OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify);
void OnDraw(HWND hwnd, HDC hdc);
void OnPaint(HWND hwnd);
INT_PTR CALLBACK DialogProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
INT WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR     lpCmdLine,
                   INT       nCmdShow);

#endif // CALCRECT_H_
