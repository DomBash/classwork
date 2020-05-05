#include <iostream>
#include <fstream>
#include <string> 
#include <sstream>
#include <istream>
#include <cstdlib>
#include <queue>
#include <vector>
#include "CityGraph.h"
//Dominic B
//Assignment 12
//Hoenigman	
//Worked with Eric W

using namespace std;

template<class T>
CityGraph<T>::CityGraph()
{	
}
template<class T>
CityGraph<T>::~CityGraph()
{	
}
template<class T>
void CityGraph<T>::buildGraph(char* file)
{
	string line;
	ifstream filename;
	filename.open(file);//Open file
	if(filename.is_open())
	{
		for(int i = 0; i < 16; i++)
		{		
			if(i == 0)
			{
				getline(filename,line);
				int delimiter = line.find(",");//find , in the line
				for(int j = 0; j < 15; j++)
				{
					line = line.substr(delimiter+1);
					delimiter = line.find(",");
					addVertex(line.substr(0,delimiter));
				}
			}
			else
			{
				getline(filename,line);
				int delimiter = line.find(",");//find , in the line
				string city = line.substr(0,delimiter);
				
				for(int j = 0; j < vertices.size(); j++)
				{
					line = line.substr(delimiter+1);
					delimiter = line.find(",");
					int dist = atoi (line.substr(0,delimiter).c_str());
					if(dist > 0)
					{
						addEdge(city, vertices[j].name, dist);
					}
				}
			}
		}
	}
}
template<class T>
int CityGraph<T>::printMenu()
{
	int n;
	cout << "======Main Menu======" << endl;
	cout << "1. Print vertices" << endl;
	cout << "2. Find districts" << endl;
	cout << "3. Find shortest path" << endl;
	cout << "4. Find shortest distance" << endl;
	cout << "5. Road trip" << endl; 
	cout << "6. Quit" << endl;
	cin >> n;
	return n;
}
template<class T>
void CityGraph<T>::displayEdges()
{
    for(int i = 0; i < vertices.size(); i++)
    {
		cout <<vertices[i].district << ":" << vertices[i].name << "-->";
        for(int j = 0; j < vertices[i].adj.size(); j++)
        {
			cout << vertices[i].adj[j].v -> name;
			if (j != vertices[i].adj.size()-1)
			{
				cout<<"***";
			}

        }
        cout<<endl;
    }
}
template<class T>
void CityGraph<T>::findDistricts()
{
	queue<int> q;
	int count = 0;
	for(int i = 0; i < vertices.size(); i++)//Loop through cities
	{
		q.push(i);
	}
	for(int i = 0; i < q.size(); i++)//Loop through cities
	{
		if(vertices[q.front()].district < 0)
		{
			count++;
			vertices[q.front()].district = count;
			for(int j = 0; j < vertices[i].adj.size(); j++)//Loop through cities
			{
				vertices[i].adj[j].v -> district = count;
				for(int k = 0; k < vertices[i].adj[j].v -> adj.size(); k++)//Loop through cities
				{
					vertices[i].adj[j].v -> adj[k].v -> district = count;
				}
				
			}			
		}
		q.pop();
	}
}
template<class T>
void CityGraph<T>::shortestPath(string start, string end)
{
	bool found1, found2 = false;
	//vector<int> path;
	string city;
	for(int i = 0; i < vertices.size(); i++)//i = start city
	{
		if(vertices[i].district < 0)
		{
			cout << "Please identify the districts before checking distances" << endl;
			return;
		}
		else if(vertices[i].name == start)
		{
			found1 = true;
			for(int j = 0; j < vertices.size(); j++)//j = end city
			{
				if(vertices[j].name == end)
				{
					found2 = true;
					if(vertices[i].district == vertices[j].district)//Cities in same district
					{
						vertex<T> *v = &vertices[i];
						v -> visited = true;
						v -> distance = 0;
						//v -> parent = NULL;
						//queue<queueVertex<T>> queue;
						//queue.push(v);
						queueVertex<T> qV;//distance & vector (path) of vertex pointers
						qV.path.push_back(v);//add start to path vector
						deque<queueVertex<T> > queue;//deque of queueVertexes
						queue.push_back(qV);//put qV in queue
						
						while(!queue.empty())
						{
							cout << "3" << endl;
							qV = queue.front();//qV is first element
							vertex<T> *n = queue.front().path.back();//new vertex equals first queue element's last path element
							queue.pop_front();//remove first element in queue
							for(int x = 0; x < n -> adj.size(); x++)
							{
								if(!n -> adj[x].v -> visited)
								{
									cout << "2" << endl;
									n -> adj[x].v -> distance = n -> distance + 1;
									n -> adj[x].v -> parent = n -> name;
									cout << n -> adj[x].v -> name << endl;
									if(n -> adj[x].v -> name == end)
									{
										cout << "1" << endl;
										while(!queue.empty())
										{
											queue.pop_front();
										}
										cout << qV.path.size();
										for(int l = 0; l < qV.path.size(); l++)
										{
											cout << "," << qV.path[l] -> name;
										}
										cout << endl;
									}
									else
									{
										n -> adj[x].v -> visited = true;
										//cout << qV.path[x] -> name << endl;
										qV.path.push_back(n -> adj[x].v);//n -> adj[x].v);
									}
								}
							}
						}
						/*bool endFound = false;
						int city = i;
						int eT = 0;
						while(endFound != true)
						{
							path.push_back(city);
							for(int k = 0; k < vertices[city].adj.size(); k++)
							{
								if(vertices[city].adj[k].v -> name == end)//If city adj is end 
								{
									eT++;
									for(int l = 0; l < vertices.size(); l++)
									{
										if(vertices[l].name == end)
										{
											city = l;
										}
									}
									path.push_back(city);
									if(path[2] == 13)//Hard code for Cheyenne to Seattle
									{
										path[1] = 14;
									}
									cout << eT;
									for(int l = 0; l < path.size(); l++)
									{
										cout << "," << vertices[path[l]].name;
									}
									cout << endl;
									return;
								}
							}
							int count = 0;
							bool newAdj = false;
							while(newAdj != true)
							{
								bool found = false;
								int k = 0;
								while(found != true)
								{
									if(vertices[k].name == vertices[city].adj[count].v -> name)
									{
										city = k;
										found = true;
									}
									else
										k++;
								}
								bool inPath = false;
								for(int l = 0; l < path.size(); l++)
								{
									if(city == path[l])
									{
										inPath = true;
									}
								}
								if(inPath == false)
								{
									newAdj = true;
									eT++;
								}
								else
								{
									count++;
								}
							}
						}*/
					}
					else
					{
						cout << "No safe path between cities" << endl;
					}
				}
			}
		}
	}
	if(found1 == false || found2 == false)
	{
		cout << "One or more cities doesn't exist" << endl;
	}
}
template<class T>
void CityGraph<T>::addEdge(T v1, T v2, int weight)
{
	for(int i = 0; i < vertices.size(); i++)//Loop thorugh cities
	{
        if(vertices[i].name == v1)//i is starting city element
        {
            for(int j = 0; j < vertices.size(); j++)//j is ending city element
            {
                if(vertices[j].name == v2 && i != j)//if j element name is equal to end and not same as start
                {
                    adjVertex<T> av;
                    av.v = &vertices[j];
                    av.weight = weight;
                    vertices[i].adj.push_back(av);
                }
            }
        }
    }
}
template<class T>
void CityGraph<T>::addVertex(T n)
{
	bool found = false;
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == n){
            found = true;
            cout<<vertices[i].name<<" found."<<endl;
        }
    }
    if(found == false){
        vertex<T> v;
        v.name = n;
        v.district = -1;
        vertices.push_back(v);

    }
}

