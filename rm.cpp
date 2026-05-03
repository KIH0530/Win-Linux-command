#include <iostream>
#include <filesystem>
using namespace std;

int main(int argc, char* argv[]){
    if (argc == 1){
        cout << "Error : No Files To Remove!" << endl;
        return 0;
    } else {
        for (int i = 1; i < argc ; i++) {
            filesystem::remove(argv[i]);
        }
    }
}