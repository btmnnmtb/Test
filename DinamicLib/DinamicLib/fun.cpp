// dllmain.cpp : Определяет точку входа для приложения DLL.
#include "pch.h"
#include <string>
using namespace std;


extern "C" __declspec(dllexport) bool AllCharacters(const char* str, const char* chars) {
    string s(str);
    string c(chars);
    for (char ch : c) {
        if (s.find(ch) == string::npos) {
            return false;
        }
    }
    return true;
}
