#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	int position{ 0 };
	string name{};
	char content{};
	string alphabets{ "*ABCD.EFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789! @#$%^&()-_=+-/,<>?;{}[]|:'\n'" };
	string key{ " .:|][}{;?><,-+=_-/)(&^%$#@!9876543210XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr*'\n'" };
	cout << "Enter name of the file to encrypt : ";
	cin >> name;
	name += ".txt";

	ifstream in_file;
	in_file.open(name);
	ofstream out_file{ "text.txt" };

	if (!in_file || !out_file) {
		cerr << "\nUnable to open file. Try again!" << endl;
	}
	else {
		cout << "\n\n\t\t\tText file has been encrypted! New encrypted file created" << endl << endl;
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

	ifstream i_file;
	i_file.open("text.txt");
	ofstream o_file{ "decrypter.txt" };

	if (!i_file) {
		cerr << "\nUnable to open text.txt file. Try again!" << endl;
	}

	if (!o_file) {
		cerr << "\nUnable to open decrypted.txt file. Try again!" << endl;
	}

	char c{};
	while (i_file.get(c)) {
		for (int i = 0; i < alphabets.length(); i++) {
			if (c == key[i]) {
				position = i;
				break;
			}
		}

		c = alphabets[position];
		o_file.put(c);
		position = 0;
	}

	o_file.close();
	i_file.close();
	cout << endl << endl;

	return 0;
}


