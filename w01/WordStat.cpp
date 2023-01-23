//Name : Sang Woo, Shin
//Student ID : 119294213
//Email : sshin36@myseneca.ca
//Section Information Code : NCC

#include <iostream>
#include "Word.h"
using namespace sdds;
using namespace std;
int main()
{
    char filename[256];
    programTitle();
    cout << "Enter filename: ";
    cin >> filename;
    wordStats(filename);
    return 0;
}