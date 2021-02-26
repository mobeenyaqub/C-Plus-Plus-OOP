#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cctype>
#include <iomanip>
#include <cstdio>
using namespace std;

int choice{};
string username{};
string password{};
string username_password{};

void check();
void choice_handler();
void username_check();
void password_check();
void file_write();
void failed_attempt();
void username_validator();
void password_validator();

int main()
{
    check();
    choice_handler();
   
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

void choice_handler() {
    if (choice == 1) {
        username_check();
        username_password = username + " ";
        password_check();
        username.clear();
    }
    else {
        username_check();
        username_validator();
    }
}

void username_check() {

    bool check = true;
    cin.ignore();

    int position{ 0 };
    string alphabets{ "*ABCD.EFGHIJKLMNOPQRST\"UVWXYZ\'abcdefghijklmnopqrstuvwxyz0123456789! @#$%^&()_=+-/,<>?;{}[]|:'\n'" };
    string key{ " GJHQD.;<,-/(^!502}96>18?34:7X]ZN+LWEB\"[YV&TKF$UOMP|CIAS\'Rxznlw_ebgjh%qdyv)tkfu@ompc=i{as#r*'\n'" };

    if (choice == 1) {

        char chk = false;
        cout << "Create a new username : ";
        getline(cin, username);

        ifstream x_file{ "login.txt" };
        ofstream y_file{ "decrypter.txt" };

        char c{};
        while (x_file.get(c)) {
            for (int i = 0; i < alphabets.length(); i++) {
                if (c == key[i]) {
                    position = i;
                    break;
                }
            }

            c = alphabets[position];
            y_file.put(c);
            position = 0;
        }
        x_file.close();
        y_file.close();

        remove("decrypter.txt");
        ifstream i_file{ "decrypter.txt" };
        string un{};
       

        while (i_file >> un)
            if (un == username){
                chk = true;
                break;
            }

        i_file.close();

        if (chk) {
            cout << setw(120) << setfill('*') << "" << endl << endl << setfill(' ');
            cout << setw(85) << right << "Username already taken. Try again. Press Enter" << endl << endl;
            cout << setw(120) << setfill('*') << "" << endl << endl << setfill(' ');
            username_check();
        }


    }
    else {
        cout << "Enter username : ";
        getline(cin, username);
    }
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
   
}

void password_check() {

    static bool check = true;

    if (choice == 1)
        cout << "Create your password : ";
    else
        cout << "Enter your password : ";
    getline(cin, password);
    cout << endl;

    auto loc = find(password.begin(), password.end(), ' ');

    if (loc != password.end()) {
        cout << setw(120) << setfill('-') << "" << endl << endl << setfill(' ');
        cerr << setw(100 - password.size()) << right << "Password mustn't include space" << endl << endl;
        cout << setw(120) << setfill('-') << "" << endl << endl << setfill(' ');
        check = false;
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
        password_check();
    }
    else {
        check = true;
    }

    if (choice == 1 && check){
        username_password += password;
        file_write();
    }
    cin.ignore();

}

void file_write() {
    ofstream out_file{ "login.txt",ios::app };
    ifstream in_file{ "encrypt.txt" };
    ofstream o_file{ "encrypt.txt" };

    cout << setw(120) << setfill('-') << "" << endl << endl << setfill(' ');
    cout << setw(70) << right << "Press enter to quit" << endl << endl;
    cout << setw(120) << setfill('-') << "" << endl << endl << setfill(' ');
    o_file << username_password << endl;

    int position{ 0 };
    char content{};
    int choice{};
    string alphabets{ "*ABCD.EFGHIJKLMNOPQRST\"UVWXYZ\'abcdefghijklmnopqrstuvwxyz0123456789! @#$%^&()_=+-/,<>?;{}[]|:'\n'" };
    string key{ " GJHQD.;<,-/(^!502}96>18?34:7X]ZN+LWEB\"[YV&TKF$UOMP|CIAS\'Rxznlw_ebgjh%qdyv)tkfu@ompc=i{as#r*'\n'" };

    while (in_file.get(content)) {

        for (int i = 0; i < alphabets.length(); i++) {
            if (content == alphabets[i]) {
                position = i;
                break;
            }
        }

        content = key[position];
        out_file.put(content);
        position = 0;
    }

    remove("encrypt.txt");
    out_file.close();
    in_file.close();
    o_file.close();

    username_password.clear();
   
}

void failed_attempt() {

    string str{};

    try {

        cout << setw(120) << setfill('\6') << "" << endl << endl;
        cout << setfill(' ');
        cerr << setw(82) << right << "Username isn't registered in our database." << endl << endl;
        cout << setw(69) << right << "Create a new account?\n\n" << setw(100) << right << "Press 1 to create a new account or press any key to retry entering username" << endl << endl;
        cout << setw(67) << right << "Enter your choice : ";
        cin >> str;
        cout << endl;
        cout << setw(120) << setfill('\6') << "" << endl;
        cout << setfill(' ');

        cout << endl;

        stringstream ss{ str };
        if (ss >> choice) {
            choice_handler();
        }
        else {
            throw 1;
        }

    }
    catch (int& ex) {
        cout << setw(120) << setfill('-') << "" << endl << endl << setfill(' ');
        cerr << setw(75) << right << "Please enter a valid choice!" << endl << endl;
        cout << setw(120) << setfill('-') << "" << endl << endl << setfill(' ');
        failed_attempt();
    }

}

void username_validator() {

    int position{ 0 };
    int choice{};
    string alphabets{ "*ABCD.EFGHIJKLMNOPQRST\"UVWXYZ\'abcdefghijklmnopqrstuvwxyz0123456789! @#$%^&()_=+-/,<>?;{}[]|:'\n'" };
    string key{ " GJHQD.;<,-/(^!502}96>18?34:7X]ZN+LWEB\"[YV&TKF$UOMP|CIAS\'Rxznlw_ebgjh%qdyv)tkfu@ompc=i{as#r*'\n'" };

    ifstream x_file{ "login.txt" };
    ofstream y_file{ "decrypter.txt" };

    char c{};
    while (x_file.get(c)) {
        for (int i = 0; i < alphabets.length(); i++) {
            if (c == key[i]) {
                position = i;
                break;
            }
        }

        c = alphabets[position];
        y_file.put(c);
        position = 0;
    }
    x_file.close();
    y_file.close();

    ifstream i_file{ "decrypter.txt" };
    string un{};
    bool check = false;

    while (i_file >> un)
        if (un == username)
            check = true;

    i_file.close();

    if (!check)
        failed_attempt();
    else{
        password_check();
        password_validator();
    }

    remove("decrypter.txt");

}

void password_validator() {
    ifstream i_file{ "decrypter.txt" };
    string pw{};
    bool check = false;

    while (getline(i_file, pw)) {
        if (pw == username + ' ' + password) {
            check = true;
            break;
        }
    }

    if (!check) {
        cout << setw(120) << setfill('*') << "" << endl << endl << setfill(' ');
        cerr << setw(80) << right << "Incorrect password entered. Try again" << endl << endl;
        cout << setw(120) << setfill('*') << "" << endl << endl << setfill(' ');
        password_check();
        password_validator();
    }
    else {
        cout << setw(120) << setfill('+') << "" << endl << endl << setfill(' ');
        cerr << setw(67) << right << "You're logged in" << endl << endl;
        cout << setw(120) << setfill('+') << "" << endl << endl << setfill(' ');
    }

    i_file.close();
}