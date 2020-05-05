#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
//TODO: add appropriate includes

using namespace std;

// ----------------------------------------------------------------------
class customVector{
  public:
    void printVector();
    void reverseVector();
    void removeAll();
    void removeElement(int n);
    vector<int> intVec;

};
// ----------------------------------------------------------------------
void customVector::printVector(){
  cout << "Elements of Integer Vector: " << endl;
  if(intVec.empty())
  {
	  cout << "0" << endl;
  }
  else
  {
	  vector<int>::iterator iter;
	  for(iter = intVec.begin(); iter != intVec.end(); iter++)
	  {
		  cout << (*iter) << endl;
	  }
  }
}

void customVector::reverseVector(){
	reverse(intVec.begin(), intVec.end());
}

void customVector::removeAll(){
  cout << "Removing all elements from the vector: " << endl;
  while(!intVec.empty())
  {
	  intVec.pop_back();
  }
}

void customVector::removeElement(int n){
	vector<int>::iterator iter;
	for(iter = intVec.begin(); iter != intVec.end(); iter++)
	{
		if(*iter == n)
		{
			intVec.erase(iter);
		}
	}
  //TODO: remove a specific element from the vector
  
}

// ----------------------------------------------------------------------
int main(){
  customVector vec1;
  auto numbers = {1,2,3,4,5,6,7,8};
  for (auto num : numbers){
    vec1.intVec.push_back(num);
  }

  vec1.printVector();

  vec1.reverseVector();
  vec1.printVector();

  vec1.removeElement(4);
  vec1.printVector();

  vec1.removeAll();
  vec1.printVector();

  return 0;
}
