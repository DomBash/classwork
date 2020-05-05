#include<iostream>

using namespace std;

struct Word{
	int n;
	string p;
};

void changeAddress(Word *a)
{
	Word *b = new Word[10];
	a = b;
	a[0].n = 5;
}
Word *changeAndReturn(Word *a)
{
	Word *b = new Word[10];
	a = b;
	a[0].n = 5;
	return a;
}
void changeArray(Word *&a)
{
	
}
int main()
{
	Word *a = new Word[5];
	changeAddress(a);
	cout << a[0].n << endl;
	a = changeAndReturn(a);
	cout << a[0].n << endl;
}

