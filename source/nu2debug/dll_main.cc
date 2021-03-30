// dll_main.cc
// Copyright 2021 averysumner
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

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
