// Name: Dominic B
// Date: 11/12/15
// Assignment: Homework #8
// Description: Keep track of the books

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Book
{
	private:
		string author;
		string title;
	public:
		Book();
		Book (string author,string title);
		string getAuthor();
		string getTitle();
		void setAuthor(string);
		void setTitle(string);
		string toString();
};
Book::Book()
{
	toString();
}
Book::Book(string author, string title)
{
	author = getAuthor();
	setAuthor(author);
	title = getTitle();
	setTitle(title);
	toString();
}
string Book::getAuthor()
{
	ifstream books_file;//input file stream
	books_file.open("books.txt");//open file
	string line;
	string author;
	if (books_file.is_open())
	{
		while ( getline (books_file,line))//read each line
		{
			int index = line.find(",");
			author = line.substr(0,index);
		}
		books_file.close();//close file
	}
	return author;
}
string Book::getTitle()
{
	ifstream books_file;//input file stream
	books_file.open("books.txt");//open file
	string line;
	string title;
	if (books_file.is_open())
	{
		while ( getline (books_file,line))//read each line
		{
			int index = line.find(",");
			title = line.substr(index+1);
		}
		books_file.close();//close file
	}
	
	return title;
}
void Book::setAuthor(string a)
{
	author = a;
}
void Book::setTitle(string t)
{
	title = t;
}
string Book::toString()
{
	string output = title + "by" + author;
	return output;
}
