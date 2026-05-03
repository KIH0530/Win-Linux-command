#include <fstream>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]){
	if (argc == 1){
		cout << "Error : No Files To Create!" << endl;
		return 0;
	} else {
		for (int i = 1; i < argc ; i++) {
			ofstream fout(argv[i]);
			fout << nullptr << endl;
			fout.close();
		}
	}
}
