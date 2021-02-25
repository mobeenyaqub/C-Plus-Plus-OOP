#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cctype>
#include <iomanip>
using namespace std;

int choice{};
string username_password{};

void check();
void username_check();
void password_check();

int main()
{
    ofstream out_file{ "login.txt",ios::app };
    ifstream in_file{ "login.txt",ios::app };

    check();
    username_check();
    out_file << username_password << endl;
    username_password.clear();

    return 0;
}

void check() {
    string str{};
    try {

        cout << setw(130) << setfill('\4') << "" << endl << endl << setfill(' ');
        cout << setw(70) << right << "Press 1 for new account" << endl;
        cout << setw(75) << right << "Press 2 for existing account" << endl << endl;
        cout << setw(130) << setfill('\4') << "" << endl << endl << setfill(' ') << endl;
        cout << setw(67) << "Enter your choice : ";
        cin >> str;
        cout << endl;

        stringstream ss{ str };
        if (ss >> choice) {
            if (choice < 1 || choice > 2) {
                throw std::string{ "Enter the correct option" };
            }
        }
        else {
            throw 1;
        }

    }
    catch (int& ex) {
        cout << setw(120) << setfill('-') << "" << endl << endl << setfill(' ');
        cerr << setw(75) << right << "Please enter a valid choice!" << endl << endl;
        cout << setw(120) << setfill('-') << "" << endl << endl << setfill(' ');
        check();
    }
    catch (string& ex) {
        cout << setw(120) << setfill('X') << "" << endl << endl << setfill(' ');
        cerr << setw(70) << right << ex << endl << endl;
        cout << setw(120) << setfill('X') << "" << endl << endl << setfill(' ');
        check();
    }

}

void username_check() {

    string username{};
    bool check = true;

    if (choice == 1) {

        cin.ignore();
        cout << "Create a new username : ";
        getline(cin, username);
        cout << endl;

        auto loc = find(username.begin(), username.end(), ' ');

        for (int i = 0; i < username.length(); i++) {
            if (ispunct(username[i]))
                check = false;
        }

        if (loc != username.end() || !check) {
            cout << setw(120) << setfill('*') << "" << endl << endl << setfill(' ');
            cerr << setw(83) << right << "Username mustn't include space or punctuation" << endl << endl;
            cout << setw(120) << setfill('*') << "" << endl << endl << setfill(' ');
            username_check();
        }
        else {
            username_password = username + "  ";
            password_check();
        }

    }
}

void password_check() {

    string password{};
    static bool check = true;
    cout << "Create your password : ";
    getline(cin, password);
    cout << endl;

    auto loc = find(password.begin(), password.end(), ' ');

    if (loc != password.end()) {
        cout << setw(120) << setfill('-') << "" << endl << endl << setfill(' ');
        cerr << setw(80 - password.size()) << right << "Password mustn't include space" << endl << endl;
        cout << setw(120) << setfill('-') << "" << endl << endl << setfill(' ');
        check = false;
        cin.ignore();
        password_check();
    }
    else {
        check = true;
    }

    if (password.size() < 8) {
        cout << setw(120) << setfill('-') << "" << endl << endl << setfill(' ');
        cerr << setw(80 - password.size()) << right << "Password should contain atleast 8 characters" << endl << endl;
        cout << setw(120) << setfill('-') << "" << endl << endl << setfill(' ');
        check = false;
        cin.ignore();
        password_check();
    }
    else {
        check = true;
    }

    if (check)
        username_password += password;
   
}