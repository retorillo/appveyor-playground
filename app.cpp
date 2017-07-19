#include "app.h"

int CALLBACK WinMain(HINSTANCE i, HINSTANCE p, LPSTR c, int n) {
  auto foobar = combine(L"C:\\foo\\bar", L"..\\bar");
  MessageBoxW(NULL, foobar.c_str(), L"test", MB_OK);
  return foobar != L"C:\\foo\\bar";
}
std::wstring combine(std::wstring l, std::wstring r) {
  auto L = l.length() + r.length() + 1;
  WCHAR* b = new WCHAR[L];
  PathCchCombine(b, L, l.c_str(), r.c_str());
  std::wstring w(b);
  delete b;
  return w;
}
