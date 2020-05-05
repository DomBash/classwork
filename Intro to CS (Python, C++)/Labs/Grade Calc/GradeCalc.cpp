// Name: Dominic B
// Date: 10/15/15
// Assignment: Grade Calc
// Description: Read in a file and analyze the data

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
	
	ifstream percentGrade;
	percentGrade.open(argv[1]);
	
	ifstream grades;
	grades.open(argv[2]);

	float sum = 0.0;
	float count = 0.0;
	float percent = 0.0;
	float finalGrade = 0.0;

	string score = "";

	while(grades >> score)
	{
		sum = sum+ stof(score);
		count += 1;
		if(grades.peek() == '\n')
		{
			float avgScore = sum/count;
			string percentString;
			getline(percentGrade, percentString);
			int index = percentString.find(" "); 
			percent = stof(percentString.substr(index + 1));
			percent = percent/100.0;
			finalGrade += percent*avgScore;
			sum = 0.0;
			count = 0.0;
		}
	}
	cout << "Final Grade: " << finalGrade << endl;

	grades.close();
	percentGrade.close();

	return 0;	
}


