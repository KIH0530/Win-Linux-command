#include <fstream>
#include <windows.h>
using namespace std;
int main(int argc, char* argv[]){
    SetConsoleOutputCP(65001);
    if (argc == 1){
        cout << "Error : No Files To Display!" << endl;
        return 0;
    } else {
        for (int i = 1; i < argc ; i++) {
            ifstream fin(argv[i]);
            if (!fin) {
                cerr << "Error: Could not open file " << argv[i] << endl;
                continue;
            }
            cout << fin.rdbuf(); // Display file contents
            fin.close();
        }
    }
    SetConsoleOutputCP(936);
}