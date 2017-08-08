#include "app.h"

int CALLBACK WinMain(HINSTANCE i, HINSTANCE p, LPSTR c, int n) {
  auto foobar = combine(L"C:\\foo\\bar", L"..\\bar");
  MessageBoxW(NULL, foobar.c_str(), L"test", MB_OK);
  return foobar != L"C:\\foo\\bar";
}
std::wstring combine(std::wstring l, std::wstring r) {
  WCHAR* b;
  PathAllocCombine(l.c_str(), r.c_str(), PATHCCH_ALLOW_LONG_PATHS, &b);
  std::wstring w(b);
  LocalFree(b);
  return w;
}
