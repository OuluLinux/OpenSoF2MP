// Simple header file to dispatch to the relevant platform API headers
#ifndef _PLATFORM_H
#define _PLATFORM_H

#if defined(_WINDOWS)
#include <windows.h>
#endif

#if defined (__linux__)
// Basic Windows type definitions for Linux
typedef const char *LPCTSTR;
typedef const char *LPCSTR;
typedef unsigned long DWORD;
typedef unsigned int UINT;
typedef void* HANDLE;
typedef HANDLE HINSTANCE;
typedef void *PVOID;
typedef DWORD COLORREF;
typedef unsigned char BYTE;

// Avoid conflict with C++17 std::byte by using a different approach
// Define our own byte type to avoid conflicts with C++17 std::byte
#ifdef __cplusplus
// Prevent std::byte from being defined
#ifdef __cpp_lib_byte
#undef __cpp_lib_byte
#endif

// Undefine any existing byte definition
#ifdef byte
#undef byte
#endif
#endif

typedef unsigned char byte;

typedef long LONG;
typedef struct tagPOINT {
  LONG x;
  LONG y;
} POINT;
typedef unsigned short USHORT;
typedef unsigned short WORD;
typedef struct _GUID {
  DWORD Data1;
  WORD  Data2;
  WORD  Data3;
  BYTE  Data4[8];
} GUID;

// Additional Windows-specific type definitions needed for force feedback
typedef void* HDC;
typedef void* HGLRC;
typedef void* HWND;
typedef void* HMODULE;
typedef void* HICON;
typedef void* HRGN;
typedef void* HBRUSH;
typedef void* HPEN;
typedef void* HFONT;
typedef void* HBITMAP;
typedef void* HCURSOR;
typedef void* HMENU;
typedef void* HACCEL;
typedef void* HPALETTE;
typedef void* HMONITOR;
typedef void* HDROP;
typedef void* HDWP;
typedef void* HRAWINPUT;
typedef void* HSZ;
typedef void* HCONV;
typedef void* HCONVLIST;
typedef void* HCONVCTX;
typedef void* HHOOK;
typedef void* HGDIOBJ;
typedef void* HGLOBAL;
typedef void* HLOCAL;
typedef void* HKL;
typedef void* HRSRC;
typedef void* HSTR;
typedef void* HTASK;
typedef void* HWINSTA;

// Win32 constants
#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif
#ifndef NULL
#define NULL 0
#endif

// Win32 function mappings
#define strnicmp Q_stricmpn
#define strcmpi Q_stricmpn
#define stricmp Q_stricmp
#define RGB(r,g,b)          ((COLORREF)((r) | ((g) << 8) | ((b) << 16)))

#define DLL_EXT "so"
#endif

#if defined (MACOS_X)
typedef const char *LPCTSTR;
typedef const char *LPCSTR;
typedef unsigned long DWORD;
typedef unsigned int UINT;
typedef void* HANDLE;
typedef HANDLE HINSTANCE;
typedef void *PVOID;
typedef DWORD COLORREF;
typedef unsigned char BYTE;

// Avoid conflict with C++17 std::byte
#ifdef __cplusplus
#ifdef __cpp_lib_byte
#undef __cpp_lib_byte
#endif
#ifdef byte
#undef byte
#endif
#endif

typedef unsigned char byte;

typedef long LONG;
typedef struct tagPOINT {
    LONG x;
    LONG y;
} POINT;
typedef unsigned short USHORT;
typedef unsigned short WORD;
typedef struct _GUID {
    DWORD Data1;
    WORD  Data2;
    WORD  Data3;
    BYTE  Data4[8];
} GUID;

// Additional Windows-specific type definitions needed for force feedback
typedef void* HDC;
typedef void* HGLRC;
typedef void* HWND;
typedef void* HMODULE;
typedef void* HICON;
typedef void* HRGN;
typedef void* HBRUSH;
typedef void* HPEN;
typedef void* HFONT;
typedef void* HBITMAP;
typedef void* HCURSOR;
typedef void* HMENU;
typedef void* HACCEL;
typedef void* HPALETTE;
typedef void* HMONITOR;
typedef void* HDROP;
typedef void* HDWP;
typedef void* HRAWINPUT;
typedef void* HSZ;
typedef void* HCONV;
typedef void* HCONVLIST;
typedef void* HCONVCTX;
typedef void* HHOOK;
typedef void* HGDIOBJ;
typedef void* HGLOBAL;
typedef void* HLOCAL;
typedef void* HKL;
typedef void* HRSRC;
typedef void* HSTR;
typedef void* HTASK;
typedef void* HWINSTA;

#define strnicmp Q_stricmpn
#define strcmpi Q_stricmpn
#define stricmp Q_stricmp
#define RGB(r,g,b)          ((COLORREF)((r) | ((g) << 8) | ((b) << 16)))

#define _isnan isnan
#define DLL_EXT "dylib"
#endif

#endif