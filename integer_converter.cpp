#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <sstream>
using namespace std;

void converter(int num) {
    cout << showbase << endl << endl;
    cout << setw(50) << right << num << " in decimal = " << setw(18) << right << dec << num << endl;
    cout << setw(50) << right << num << " in hexadecimal = " << setw(15) << right << hex << num << endl;
    cout << setw(51) << right << num << " in octal = " << setw(20) << right << oct << num << endl;
}

int main() {
   
    char choice{};
    int num{};
    string number{};

    cout << setw(70) << right << "Integer Converter" << endl << endl << endl << endl;

    cout << "Enter a number for conversion : ";
    cin >> number;

    stringstream ss{ number };
   
    try {
        if (ss >> num) {
            converter(num);
        }
        else {
            throw 1;
        }
    }
    catch (int& ex) {
        cout << "Error caught! Please enter a number" << endl;
    }


    return 0;
}

