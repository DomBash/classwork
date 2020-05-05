#include <iostream>

using namespace std;

void bubbleSort(int A[], int length){
	cout<<"A in bubble osrt"<<A<<endl;
	//lenght has diff addr the length in main
	//
	cout<<"addr of length in bubblesort"<<&length<<endl;
	for (int i = 0; i < length - 1; i++){
		for(int j = 0; j < length - i - 1; j++){
			if(A[j] > A[j+1]){
				int swap = A[j];
				A[j] = A[j+1];
				A[j+1] = swap;
			}
		}
	}
}

int main(){
	int A[4] = {45, 44, 32, 23};
	int length = 4;
	cout<<"address of length in main"<<&length<<endl; //& is address of
	bubbleSort(A, 4);
	cout<<"A in main"<<endl;
	//A is a pointer - reference to mem loaction
	//any mod to loaction is observed anywhere location u
	for(int i = 0; i < 4; i++){
		cout << A[i]<<endl;
	}
}