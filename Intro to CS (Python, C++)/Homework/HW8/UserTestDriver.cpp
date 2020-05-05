/** Test driver for User class for Netflix
 * @author E.S.Boese  (I am the original author, keep me here)
 */
// Test User class
// Run as:  g++ -std=c++11 UserTestDriver.cpp 
// 			./a.out
#include <string>
#include <vector>
#include <iostream>
#include "User.cpp"
using namespace std;

void test(int, string what, string expectedOutput, string actualOutput);

int main()
{
	cout << "Testing User class\n\n";

	User u1 = User();
	string yourOutput = u1.toString();
	test(1, "Default Constructor", "User [user_id=Unknown]", yourOutput);

	User u2 = User("Jetti", "1 5 5 3 0 -5 0 5");
	yourOutput = u2.toString();
	test(2, "Regular Constructor", "User [user_id=Jetti]", yourOutput);

	// test case 3: getRatingAt
	yourOutput = to_string(u2.getRatingAt(0));
	test(3, "getRatingAt", "1", yourOutput);
	
	// test case 4: getNumRatings
	yourOutput = to_string(u2.getNumRatings());
	test(4, "getRatingAt", "8", yourOutput);
	
	// test case 5: printRatings
	cout << 5 << " Testing: printRatings()" << endl;
	cout << "Expected output:\n---\n" << "1 5 5 3 0 -5 0 5" << "\n---\nYour output:\n---\n";
	u2.printRatings();
	cout << "\n---\n";
	cout << "Test case 5 (manually verify)" << endl;
	cout << "-------------------------------------------\n";
	cout << endl;

	// test case 6: addRating
	//int lastIndex = u2.getNumRatings();
	u2.addRating(-3);
	yourOutput = to_string(u2.getRatingAt(u2.getNumRatings()-1));
	test(6, "addRating", "-3", yourOutput);
}

void test(int testcase, string what, string expectedOutput, string actualOutput)
{
	cout << testcase << " Testing: " << what << endl;
	cout << "Expected output:\n---\n" << expectedOutput << "\n---\nYour output:\n---\n";
	cout << actualOutput << "\n---\n";
	cout << "Test case " << testcase << " " << (expectedOutput == actualOutput ? "Correct" : "Wrong") << endl;
	cout << "-------------------------------------------\n";
}
