#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
using namespace std;

int main() 
{
	ofstream out_file{ "record.csv",ios::app };
	ifstream in_file{ "record.csv" };

	int choice{};
	string name{};
	int marks{};
	string str{};
	string n{};
	int num{};

	do{
		string s{};
		
		try{
			cout << setw(45) << right << "" << setw(10) << right << "Press 1 : " << setw(50) << left << "Search Student" << endl;
			cout << setw(45) << right << "" << setw(10) << right << "Press 2 : " << setw(50) << left << "Add Student Record" << endl;
			cout << setw(45) << right << "" << setw(10) << right << "Press 3 : " << setw(50) << left << "Display Record" << endl << endl;
			cout << setw(65) << right << "Enter your choice : ";
			cin >> s;
			cout << endl;
			stringstream ss{ s };
			if (ss >> choice) {

			}
			else {
				throw 1;
			}
		}
		catch (int& ex) {
			choice = 0;
			cout << endl;
		}
	} while (choice < 1 || choice > 3);

	if (choice == 1 || choice == 2) {
		cout << setw(69) << right << "Enter name of student : ";
		cin.ignore();
		getline(cin, name);
		cout << endl << endl;
	}
	else {
		cout << endl << endl;
	}

	if (choice == 1) {
		char check = false;
		name += ",";

		while (getline(in_file, str)){

			stringstream ss{ str };

			ss >> n >> num;
		
			if (n == name){
				cout << setw(52) << right << n << " has obtained " << num << " marks" << endl;
				check = true;
			}
		}

		if (!check) {
			cout << setw(53) << right << name << " not found " << endl;
		}

	}
	else if(choice == 2) {
		string s{};
		bool check = false;

		do{
			while(!check){
				try{
					cout << setw(69) << right << "Enter marks obtained by " << name << " : ";
					cin >> s;
					stringstream se{ s };
					cout << endl;
					if (se >> marks) {
						check = true;
					}
					else {
						throw 1;
					}
				}
				catch (int& ex) {
				
				}
			}
			check = false;
		} while (marks < 0 || marks>100);

		cout << endl << setw(69) << right << "Record Updated" << endl;
		out_file << name << ", " << marks << endl;

	}
	else {

		while (getline(in_file, str)) {

			stringstream ss{ str };
			ss >> n >> num;
			n.erase(n.length() - 1, 1);
			cout << setw(53) << right << "Names : " << setw(10) << left << n << setw(5) << left << " - " << setw(3) << left << num << endl;
			
		}
	}

	in_file.close();
	out_file.close();

	cout << endl << endl;

	return 0;
}