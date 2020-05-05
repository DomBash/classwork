#ifndef BALLMAP_H
#define BALLMAP_H

#include<vector>
#include<iostream>
struct yearS{
	int year;
	std::string team;
	std::string state;
	int sal;	
};

struct PlayerNode{
    std::string fName;
    std::string lName;
    int born;
    std::string country;
    int weight;
    int height;
    std::string bats;
    std::string throws;
    int sum;
    PlayerNode* next;
    std::vector<yearS*> TnS;
};

class BallMap
{

    public:
        BallMap(char* size);
        ~BallMap();
        void buildTable(char* file);
        int printMenu();
        void findPlayer(std::string first, std::string last);
        void chainAdd(PlayerNode* x, yearS* y);
        void addrAdd(PlayerNode* x, yearS* y);
        int hashSum(std::string first, std::string last);
        int arrSize;
        PlayerNode** chainArray;
		PlayerNode* addrArray;
		int cCollisions;
		int aCollisions;
		int cOps;
		int aOps;
		int GC;
    protected:

    private:
};

#endif // BALLMAP_H
