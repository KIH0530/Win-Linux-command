#include <iostream>
#include <filesystem>
#include <windows.h>
using namespace std;

int main(int argc, char* argv[]){
    SetConsoleOutputCP(65001);
    string path = ".";
    if (argc > 1) {
        path = argv[1];
    }
    for (const auto& entry : filesystem::directory_iterator(path)) {
        cout << entry.path().filename().string() << endl;
    }
    SetConsoleOutputCP(936);
}
