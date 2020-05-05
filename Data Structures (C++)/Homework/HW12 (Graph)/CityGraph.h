#ifndef CITYGRAPH_H
#define CITYGRAPH_H

#include<vector>
#include<iostream>

template<class T>
struct vertex;

template<class T>
struct adjVertex{
    vertex<T> *v;
    int weight;
};

template<class T>
struct queueVertex{
    int distance;
    std::vector<vertex <T>*> path;
};

template<class T>
struct vertex{
    T name;
    int district;
    bool visited;
    int distance;
    std::string parent;
    std::vector<adjVertex<T> > adj;
};

template<class T>
class CityGraph
{
    public:
        CityGraph();
        ~CityGraph();
        void addEdge(T v1, T v2, int weight);
        void addVertex(T n);
        void displayEdges();
        int printMenu();
        void buildGraph(char* file);
        void findDistricts();
        void shortestPath (std::string start, std::string end);
    protected:
    private:
        std::vector<vertex<T> > vertices;

};
#include "CityGraph.cpp"
#endif //CITYGRAPH_H
