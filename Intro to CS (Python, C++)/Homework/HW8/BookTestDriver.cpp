/** Test driver for Book class for Netflix
 * @author E.S.Boese  (I am the original author, keep me here)
 */
// Test driver program to ensure your Book class is mostly correct
// Run as: g++ -std=c++11 BookTestDriver.cpp
// 			./a.out

#include <iostream>
#include <string>
#include "Book.cpp"
using namespace std;

int main()
{
	Book b1 = Book();
	cout << "Test 1: should output:\n---\nUnknown by Unknown\n---\n";
	cout << "Your output:\n------------------  your output\n";
	cout << b1.toString() << endl;	
	cout << "------------------   end your output\n";
	cout << "Test 1 results: " << (b1.toString() == "Unknown by Unknown" ? "Correct" : "Wrong") << endl;
	cout << "------------------------------------------\n" << endl;

	Book b2 = Book("Liz Boese", "Dare to go Solo");
	cout << "Test 2: should output:\n---\nDare to go Solo by Liz Boese\n---\n";
	cout << "Your output:\n------------------  your output\n";
	cout << b2.toString() << endl;	
	cout << "------------------   end your output\n";
	cout << "Test 2 results: " << (b2.toString() == "Dare to go Solo by Liz Boese" ? "Correct" : "Wrong") << endl;
	cout << "------------------------------------------\n" << endl;
	
	cout << "Test 3: call to getAuthor should output:\n---\nLiz Boese\n---\n";
	cout << "Your output:\n------------------  your output\n";
	cout << b2.getAuthor() << endl;	
	cout << "------------------   end your output\n";
	cout << "Test 3 results: " << (b2.getAuthor() == "Liz Boese" ? "Correct" : "Wrong") << endl;
	cout << "------------------------------------------\n" << endl;
	
	cout << "Test 4: call to getTitle should output:\n---\nDare to go Solo\n---\n";
	cout << "Your output:\n------------------  your output\n";
	cout << b2.getTitle() << endl;	
	cout << "------------------   end your output\n";
	cout << "Test 4 results: " << (b2.getTitle() == "Dare to go Solo" ? "Correct" : "Wrong") << endl;
	cout << "------------------------------------------\n" << endl;
	
	cout << "Test 5: call to setAuthor should output:\n---\nCookie Monster\n---\n";
	b2.setAuthor("Cookie Monster");
	cout << "Your output:\n------------------  your output\n";
	cout << b2.getAuthor() << endl;	
	cout << "------------------   end your output\n";
	cout << "Test 5 results: " << (b2.getAuthor() == "Cookie Monster" ? "Correct" : "Wrong") << endl;
	cout << "------------------------------------------\n" << endl;
	
	cout << "Test 6: call to setTitle should output:\n---\nFun with C++\n---\n";
	b2.setTitle("Fun with C++");
	cout << "Your output:\n------------------  your output\n";
	cout << b2.getTitle() << endl;	
	cout << "------------------   end your output\n";
	cout << "Test 4 results: " << (b2.getTitle() == "Fun with C++" ? "Correct" : "Wrong") << endl;
	cout << "------------------------------------------\n" << endl;
	
	cout << "Test 7: private instance variables. The following lines should NOT compile:\n";
	//cout << b2.author << endl;
	//cout << b2.title << endl;


	return 0;
}
