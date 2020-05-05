#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

struct item{
	string type;
	int fsow;//for sale or wanted
	int price;

}itemArray[100];


int main()
{
	string file_name;
	cout << "What is the name of your file?" << endl;
	cin >> file_name;
	ifstream messageBoard;
	messageBoard.open(file_name.c_str());//Open file file_name.c_str()
	cout<<file_name<<endl;

	string line;
	int count = 0;
	int shiftCounter = 0;
	int fileCounter = 0;
	int searchCounter = 0;
	bool noMatch = true;
	

	if (messageBoard.is_open())
	{
		
		while ( getline (messageBoard,line))//read each line
		{
			int delimiter = line.find(",");//find , in the line
			string s1 = line.substr(0,delimiter);
			line = line.substr(delimiter+2);
			delimiter = line.find(",");
			string s2 = line.substr(0,delimiter);
			line = line.substr(delimiter+2);
			
			fileCounter++;
			
			struct item i;
			i.type = s1;
			
			if (s2 == "wanted")
				i.fsow = 1;
			else
				i.fsow= 0;
			
			istringstream(line)>>i.price;
			
				for(int n = 0; count >= n; ++n)
				{
					searchCounter++;
					if(i.type == itemArray[n].type)
					{
						if(((i.fsow == 1) && (itemArray[n].fsow == 0)) || ((i.fsow == 0) && (itemArray[n].fsow == 1)))
						{
							//cout<<i.fsow<<"and"<<itemArray[n].fsow<<endl;
							if (i.fsow == 1)
							{
								if(i.price >= itemArray[n].price)
								{
									cout<<itemArray[n].type<<" "<<itemArray[n].price<<endl;
									for (int i = n; i < count; ++i)
									{
										itemArray[i].type = itemArray[i+1].type;
										itemArray[i].fsow = itemArray[i+1].fsow;
										itemArray[i].price = itemArray[i+1].price;
										shiftCounter++;
									}
									noMatch = false;									
								}
							}
							else if(i.fsow == 0)
							{
								if(i.price <= itemArray[n].price)
								{
									cout<<itemArray[n].type<<" "<<line<<endl;
									for (int i = n; i < count; ++i)
									{
										itemArray[i].type = itemArray[i+1].type;
										itemArray[i].fsow = itemArray[i+1].fsow;
										itemArray[i].price = itemArray[i+1].price;
										shiftCounter++;		
									}
									noMatch = false;
								}
							}
						}
					}
				}
					
			if(noMatch == true)
			{
				itemArray[count].type = i.type;
				itemArray[count].fsow = i.fsow;
				itemArray[count].price = i.price;
			}
			
			itemArray[count++] = i;
			
		}
		messageBoard.close();//close file
	}
	int j = 0;
	while(j <= count)
	{		
		if(itemArray[j].fsow == 0)
		{
			cout<<itemArray[j].type<<", "<<"for sale"<<", "<<itemArray[j].price<<endl;//for sale
		}
		else
		{
			cout<<itemArray[j].type<<", "<<"wanted"<<", "<<itemArray[j].price<<endl;//wanted
		}
		cout << j<<endl;
		j++;
	}
	
	cout<<"file read:"<<fileCounter<<endl;
	cout<<"search array:"<<searchCounter<<endl;
	cout<<"shift array:"<<shiftCounter<<endl;
	

}
