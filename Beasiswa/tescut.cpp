#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main() {
    ifstream read;
    string str;
    read.open("hasilseleksi.txt");
    while (getline(read, str)) {
        //read >> str;
        cout << "Str sebelum : " << str << endl;
        str = str.substr(3,str.length());
        cout << "Str sesudah : " << str << endl << endl;
    }

    return 0;
}
