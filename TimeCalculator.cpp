#include <iostream>
using namespace std;
class Time {
private:
	int hours;
	int minutes;
	int seconds;
public:
	Time()			//default constructor to initialize at 0
	{
		hours = 0;
		minutes = 0;
		seconds = 0;
	}
	Time(int h, int m, int s)			//parameterized constructor
	{
		hours = h;
		minutes = m;
		seconds = s;
	}
	void show()				//member function to show output
	{
		if (seconds > 60)
		{
			seconds = seconds % 60;
			minutes++;

		}
		if (minutes > 60)
		{
			minutes = minutes % 60;
			hours++;

		}
		if (hours > 12)
		{
			hours = 0;
		}
		cout << hours << ":" << minutes << ":" << seconds << endl;
	}

	friend Time operator+(Time t1, Time t2)			//operator overloading for addition
	{
		Time res;
		res.hours = t1.hours + t2.hours;
		res.minutes = t1.minutes + t2.minutes;
		res.seconds = t1.seconds + t2.seconds;
		return res;
	}
	Time operator++()					//opertaor overloading for incremnent
	{
		seconds = seconds + 1;
	}
	Time operator--()					//operator overloading for decrement
	{
		if (seconds > 0) {

			seconds = seconds - 1;
		}
	}
	Time operator++(int dumy)
	{

		seconds = seconds + 1;
	}
	Time operator --(int dumy)
	{
		if (seconds > 0) {

			seconds = seconds - 1;
		}
	}
};
int main()
{
	Time  t3;
	int h, m, s;
	cout << "ENter the value of hours for 1st :";
	cin >> h;
	cout << "Enter the value for minutes for 1st:";
	cin >> m;
	cout << "Enter the value for seconds for 1st:";
	cin >> s;
	Time t1(h, m, s);
	cout << "ENter the value of hours for 2nd :";
	cin >> h;
	cout << "Enter the value for minutes for 2nd:";
	cin >> m;
	cout << "Enter the value for seconds for 2nd:";
	cin >> s;
	Time t2(h, m, s);


	t3 = t1 + t2;				//adding sum of t1 and t2 in t3
	t3.show();


	cout << endl;
	--t3;						//increment the value of second by 1
	t3.show();
	cout << endl;
	++t3;						//decrement the value of second by 1
	t3.show();
	cout << endl;
	++t3;
	t3.show();
	cout << endl;
	--t3;
	t3.show();
	cout << endl;
	return 0;
}



