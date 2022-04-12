#include <iostream>
#include <fstream>
#include <iomanip>
#include <Windows.h>
#include <vector>
#include <string.h>

using namespace std;

int main() {
    ifstream f;
    f.open("test1.txt", ios_base::in); // любой проверочный файл. извините, что не через функцию :^(
    f.seekg(0, ios::end);
    int fileSize = f.tellg();
    vector<char> fileData;
    fileData.resize(fileSize);
    f.seekg(0, ios::beg);
    f.read(&fileData[0], fileSize);
    int ar[256];
    memset(&ar[0], 0x00, sizeof(int) * 256);

    for (int i = 0; i < fileData.size(); i++) {
        ar[fileData[i]]++;
    }
    f.close();
    ofstream f2("test2.txt", ios_base::out);
    for (int i = 0; i < 256; i++) {
        if (ar[i] != 0)
            f2 << char(i) << " - " << ar[i] << "\n";
    }
    f2.close();
    return 0;
}
