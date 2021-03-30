// dll_main.cc

#include <Windows.h>

// These offsets are confirmed to work for the GOG build of LEGO® Star Wars: The Complete Saga
#define FPS_DISPLAY_ADDRESS 0x009250d4
#define POSITION_DISPLAY_ADDRESS 0x0087b734
#define LOADING_DISPLAY_ADDRESS 0x0087b530

#define FPS_DISPLAY_KEY VK_F3
#define POSITION_DISPLAY_KEY VK_F4
#define LOADING_DISPLAY_KEY VK_F5

DWORD WINAPI WorkThread(LPVOID param) {
  BOOL* fps_display = (BOOL*)FPS_DISPLAY_ADDRESS;
  BOOL* position_display = (BOOL*)POSITION_DISPLAY_ADDRESS;
  BOOL* loading_display = (BOOL*)LOADING_DISPLAY_ADDRESS;

  while (true) {
    if (GetAsyncKeyState(FPS_DISPLAY_KEY) & 1) *fps_display = !*fps_display;
    if (GetAsyncKeyState(POSITION_DISPLAY_KEY) & 1) *position_display = !*position_display;
    if (GetAsyncKeyState(LOADING_DISPLAY_KEY) & 1) *loading_display = !*loading_display;
  }
}

BOOL WINAPI DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved) {
  switch (dwReason) {
  case DLL_PROCESS_ATTACH:
    CreateThread(NULL, NULL, WorkThread, hModule, NULL, NULL);
    break;
  default:
    break;
  }
  return TRUE;
}