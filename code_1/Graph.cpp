#include "Graph.hpp"
#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#include <climits>

using namespace std;


void Graph::addEdge(string v1, string v2){

    for(unsigned int i = 0; i < vertices.size(); i++){
        if(vertices[i]->name == v1){
            for(unsigned int j = 0; j < vertices.size(); j++){
                if(vertices[j]->name == v2 && i != j){
                    adjVertex av;
                    av.v = vertices[j];
                    av.weight = -1;
                    vertices[i]->adj.push_back(av);
                    //another vertex for edge in other direction
                    adjVertex av2;
                    av2.v = vertices[i];
                    av2.weight = -1;
                    vertices[j]->adj.push_back(av2);
                }
            }
        }
    }
}




void Graph::addVertex(string n){
    bool found = false;
    for(unsigned int i = 0; i < vertices.size(); i++){
        if(vertices[i]->name == n){
            found = true;
            cout<<vertices[i]->name<<" found."<<endl;
        }
    }
    if(found == false){
        vertex * v = new vertex;
        v->name = n;
        v->distance = 0;
        vertices.push_back(v);

    }
}

void Graph::displayEdges(){
   //loop through all vertices and adjacent vertices
   for(unsigned int i = 0; i < vertices.size(); i++){
      cout<<vertices[i]->name<<" --> ";
      for(unsigned int j = 0; j < vertices[i]->adj.size(); j++){
         cout << vertices[i]->adj[j].v->name << " ";
      }
      cout<<endl;
   }
}




vertex* Graph::search(string sKey){
   vertex *vFound = nullptr;
   for(unsigned int i=0; i<vertices.size(); i++){
      if(vertices[i]->name == sKey)
         vFound = vertices[i];
   }
   return vFound;
}



void Graph::resetGraph()
{
    for (auto v : vertices) {
        v->distance = INT_MAX;
        v->visited = false;
    }
}


// ------ TODO ------


void Graph::printFurthestNodes(std::string source_name){
    // TODO
    
}