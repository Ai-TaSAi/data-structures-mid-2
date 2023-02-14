#ifndef GRAPH_H
#define GRAPH_H
#include<vector>
#include<iostream>

struct vertex;

struct adjVertex{
    vertex *v;
    int weight;
};

struct vertex{
    // Key value
    std::string name;
    // adjacency list
    std::vector<adjVertex> adj;
    
    // visited member for Breadth First Traverse
    bool visited = false;
    // distance member for BFT
    int distance = 0;

    // solved member for Dijkstra's
    bool solved = false;
    // distDijk for weighted distance
    int distDijk = 0;
};

class Graph
{
    public:
        void addVertex(std::string name); // insert method
        void addEdge(std::string v1, std::string v2); // insert edge (default weight = -1)
        void displayEdges();
        void resetGraph();
        void printFurthestNodes(std::string source_name);   // TODO: Complete definition in Graph.cpp


    private:
        std::vector<vertex*> vertices;
        vertex* search(std::string sKey);

};

#endif // GRAPH_H
