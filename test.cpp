#include <cppunittest.h>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "app.h"

TEST_CLASS(Test) {
public:
  TEST_METHOD(combine) {
    Assert::AreEqual(L"foo\\bar", ::combine(L"foo", L"bar").c_str());
  }
};
