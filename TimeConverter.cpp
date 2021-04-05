#include<iostream>
using namespace std;

class Time {
private:
	int hours;
	int minutes;
public:
	Time();
	void set_time(int h, int m);
	void change_format();
	void display_time(string) const;
};

Time::Time()
	:hours{ 00 }, minutes{ 00 }{};

void Time::set_time(int h, int m) {
	hours = h;
	minutes = m;
}

void Time::change_format() {
	hours -= 12;
}

void Time::display_time(string time_check) const {

	if (hours == 0 && minutes < 10 && time_check != " ")
		cout << "\nTime in 12 hours clock =  " << 12 << ":0" << minutes << " am" << endl;
	else if (hours == 0 && minutes >= 10 && time_check != " ")
		cout << "\nTime in 12 hours clock =  " << 12 << ":" << minutes << " am" << endl;
	else if (minutes < 10 && hours < 10 && time_check != " ")
		cout << "\nTime in 12 hours clock =  " << "0" << hours << ":0" << minutes << " " << time_check << endl;
	else if (minutes < 10 && hours >= 10 && time_check != " ")
		cout << "\nTime in 12 hours clock =  " << hours << ":0" << minutes << " " << time_check << endl;
	else if (minutes >= 10 && hours < 10 && time_check != " ")
		cout << "\nTime in 12 hours clock =  " << "0" << hours << ":" << minutes << " " << time_check << endl;
	else if (minutes >= 10 && hours >= 10 && time_check != " ")
		cout << "\nTime in 12 hours clock =  " << hours << ":" << minutes << " " << time_check << endl;
	else if (minutes < 10 && hours == 0)
		cout << "\nTime in 24 hours clock =  " << "00:0" << minutes << endl;
	else if (minutes >= 10 && hours == 0)
		cout << "\nTime in 24 hours clock =  " << "00:" << minutes << endl;
	else if (minutes < 10 && hours < 10)
		cout << "\nTime in 24 hours clock =  " << "0" << hours << ":0" << minutes << " " << time_check << endl;
	else if (minutes < 10 && hours > 10)
		cout << "\nTime in 24 hours clock =  " << hours << ":0" << minutes << " " << time_check << endl;
	else
		cout << "\nTime in 24 hours clock =  " << hours << ":" << minutes << endl;

}

int main() {

	Time time;

	unsigned hours, minutes;

	do
	{
		cout << "Enter hours (0 - 23) : ";
		cin >> hours;
	} while (hours > 23);

	do {
		cout << "Enter minutes (0 - 59) : ";
		cin >> minutes;
	} while (minutes > 59);

	if (hours < 12) {
		time.set_time(hours, minutes);
		time.display_time("am");
		time.display_time(" ");
	}
	else if (hours == 12) {
		time.set_time(hours, minutes);
		time.display_time("pm");
		time.display_time(" ");
	}
	else {
		time.set_time(hours, minutes);
		time.display_time(" ");
		time.change_format();
		time.display_time("pm");
	}

	return 0;
}
