#include <iostream>

using namespace std;

void myFunction(int *c)
{
	*c = 10;
}

int main()
{
	int *a = new int;
	int b = 5;
	int *a2 = &b;
	//myFunction(&b);
	//myFunction(a);
	//myFunction(a2);
	myFunction(&a);
	
}


