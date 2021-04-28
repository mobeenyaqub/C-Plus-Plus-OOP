#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
	string fileNameOne{}, fileNameTwo{};
	string data1{}, data2{};
	float percentage{};
	float totalLines = 0;
	float similarityCount = 0;
	bool flag1 = false, flag2 = false;

	cout << "Enter name of first file : ";
	getline(cin, fileNameOne);

	cout << "Enter name of second file : ";
	getline(cin, fileNameTwo);

	ifstream fileOne{ fileNameOne + ".txt" };
	ifstream fileTwo{ fileNameTwo + ".txt" };

	if (!fileOne)
		cout << "\nUnable to locate file : " << fileNameOne << endl;
	else
		flag1 = true;

	if (!fileTwo)
		cout << "\nUnable to locate file : " << fileNameTwo << endl;
	else
		flag2 = true;

	if (flag1 && flag2) {
		while (getline(fileOne, data1)) {
			getline(fileTwo, data2);

			if (data1 == data2)
				similarityCount++;

			totalLines++;
		}

		percentage = (similarityCount / totalLines) * 100;
		cout << "\nTotal lines : " << totalLines << endl;
		cout << "\nSimilar lines : " << similarityCount << endl;
		cout << "\nPlagiarism = " << fixed << setprecision(1) << percentage << " %" << endl << endl;

	}
	return 0;
}