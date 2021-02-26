#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

string book_name() {
	string name{}, content{};
	bool check = false;
	int count{ 0 };

	cout << "Enter the desired book name : ";
	getline(cin, name);

	ifstream in_file{ "Library.txt" };

	while (getline(in_file, content)) {

		for (auto i = 0; i < name.size(); i++) 
			if (content.at(i) == name.at(i))
				count++;
		
		if (count >= content.size() / 4) {
			check = true;
			if (check)
				cout << "\n\nYour desired book named \"" << content << "\" is available" << endl;
			break;
		}

		count = 0;
	}

	if(!check)
	cout << "\n\nUnfortunately, we don't have the requested book available" << endl;

	in_file.close();

	return name;
}

int main()
{
	cout << endl << setw(75) << "Welcome to \"Virtual Library\"" << endl << endl << endl;

	book_name();

	cout << endl << endl;
	return 0;
}
