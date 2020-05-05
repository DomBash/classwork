#ifndef DATE_H
#define DATE_H
#include <iostream>

class Date
{
	private:
		int month;
		int day;
		int year;
	public:
		Date(int m, int d, int y);
		void printDate();
		void setMonth(int m);
		
};
#endif
