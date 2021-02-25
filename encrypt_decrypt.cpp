#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdio>
using namespace std;

void choice_selector(int& choice) {
	do {
		cout << endl << setw(70) << right << "Press 1 for encryption" << endl;
		cout << setw(70) << right << "Press 2 for decryption" << endl;
		cout << setw(68) << right << "Enter your choice : ";
		cin >> choice;
	} while (choice < 1 || choice>2);

}

int main()
{
	int position{ 0 };
	string name{};
	char content{};
	int choice{};
	bool check{};
	string alphabets{ "*ABCD.EFGHIJKLMNOPQRST\"UVWXYZ\'abcdefghijklmnopqrstuvwxyz0123456789! @#$%^&()_=+-/,<>?;{}[]|:'\n'" };
	string key{ " GJHQD.;<,-/(^!502}96>18?34:7X]ZN+LWEB\"[YV&TKF$UOMP|CIAS\'Rxznlw_ebgjh%qdyv)tkfu@ompc=i{as#r*'\n'" };
	cout << "Enter name of the file : ";
	cin >> name;
	name += ".txt";

	choice_selector(choice);

	if (choice == 1) {

		ifstream in_file;
		in_file.open(name);
		ofstream out_file{ "text.txt" };

		if (!in_file) {
			cerr << "\nUnable to open read file. Try again!" << endl;
		}
		else if (!out_file) {
			cerr << "\nUnable to open write file. Try again!" << endl;
		}

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
		in_file.close();
		out_file.close();
		check = true;
	}
	else {
		ifstream x_file;
		x_file.open(name);
		ofstream y_file{ "decrypter.txt" };

		if (!x_file) {
			cerr << "\nUnable to open text.txt file. Try again!" << endl;
		}

		if (!y_file) {
			cerr << "\nUnable to open decrypted.txt file. Try again!" << endl;
		}

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
		check = false;
		x_file.close();
		y_file.close();
	}

	if (check) {
		ifstream i_file;
		i_file.open("text.txt");
		ofstream o_file;
		o_file.open(name);

		if (!i_file) {
			cerr << "\nUnable to open text.txt file. Try again!" << endl;
		}

		if (!o_file) {
			cerr << "\nUnable to open decrypted.txt file. Try again!" << endl;
		}

		string c{};
		while (getline(i_file, c)) {
			o_file << c << endl;
		}
		cout << setfill('-');
		cout << endl << setw(50) << right << "| File \4" << name << "\4 has been encrypted |" << setw(40) << left << "" << endl;

		i_file.close();
		o_file.close();
		remove("text.txt");

	}
	else {
		ifstream n_file;
		n_file.open("decrypter.txt");
		ofstream o_file;
		o_file.open(name);

		if (!n_file) {
			cerr << "\nUnable to open text.txt file. Try again!" << endl;
		}

		if (!o_file) {
			cerr << "\nUnable to open decrypted.txt file. Try again!" << endl;
		}

		string c{};
		while (getline(n_file, c)) {
			o_file << c << endl;
		}
		cout << setfill('-');
		cout << endl << setw(50) << right << "| File \4" << name << "\4 has been decrypted |" << setw(40) << left << "" << endl;

		n_file.close();
		o_file.close();
	}

	remove("text.txt");
	remove("decrypter.txt");

	cout << endl << endl;

	return 0;
}
