#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");
    string iString, sChars;
    cout << "Введите строку: ";
    getline(cin, iString);
    cout << "Введите символы для поиска: ";
    getline(cin, sChars);
    HINSTANCE load = LoadLibrary(L"DinamicLib.dll");
    if (!load) {
        cout << "Не удалось загрузить библиотеку DinamicLib.dll" << endl;
        return 1;
    }
    typedef bool (*ContainsAllCharactersFunc)(const char*, const char*);
    ContainsAllCharactersFunc AllCharacters = (ContainsAllCharactersFunc)GetProcAddress(load, "AllCharacters");
    if (!AllCharacters) {
        cout << "Не удалось найти функцию AllCharacters" << endl;
        FreeLibrary(load);
        return 1;
    }
    bool result = AllCharacters(iString.c_str(), sChars.c_str());
    if (result) {
        cout << "Да" << endl;
    }
    else {
        cout << "Нет" << endl;
    }
    FreeLibrary(load);
}
