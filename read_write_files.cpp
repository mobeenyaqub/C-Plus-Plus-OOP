#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <sstream>
using namespace std;

int main() {

    string name{}, content{};
    int i = 1;

    cout << "Enter a name to create a file or open the existing file : ";
    getline(cin, name);
    name += ".txt";

    ofstream out_file{ name };
    ifstream in_file;
    in_file.open(name);

    cout << endl << setw(85) << right << "Enter content to add to text file (double enter to exit) : " << endl << endl;
   
    if (!in_file) {
        cerr << "Unable to read the file" << endl;
    }

    if (!out_file) {
        cerr << "Unable to create the file" << endl;
    }

    while (getline(cin, content)) {
        out_file << content << endl;
        if (content == "") {
            break;
        }
    }

    cout << "Outputting the file contents : " << endl << endl;

    while (in_file >> content) {
        cout << i << " - " << content << "  ";
        i++;
    }
   
    out_file.close();
    in_file.close();

    return 0;
}

