#include <gtest/gtest.h>
#include "test_helpers.hpp"
#include "../code_1/Graph.hpp"
#include "../code_2/BST.hpp"

std::string exec(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}

std::string readFileIntoString(std::string fileName){
	std::string line, out;
  	ifstream A;
  	A.open(fileName);
  	if(!A){throw std::runtime_error("could not open file: " + fileName);}
	while(getline(A,line)){
		out = out+line+"\n";
	}
	return out;
}


string test_printFurthest(string* vertices,  int noVertices, string *edgesA, 
                            string *edgesB, int noEdges, string startVertex){
    
    Graph g1;
    for(int i = 0; i<noVertices; i++)
        g1.addVertex(vertices[i]);
    for(int i = 0; i<noEdges; i++)
        g1.addEdge(edgesA[i], edgesB[i]);
    // cout << "List of verices and their edges: " << endl;
    // g1.displayEdges();
    testing::internal::CaptureStdout();
    g1.printFurthestNodes(startVertex);
    string output = testing::internal::GetCapturedStdout();
    return output;
}

string test_outersum(int keys[], int len)
{
    BST tree;
    testing::internal::CaptureStdout();
    
    for(int i=0;i<len;i++)
    {
        cout << "[GRADER] Adding key:" <<keys[i]<< endl;
        tree.addNode(keys[i]);
    }
    
    cout<< "outer sum="<< tree.outer_sum()<<endl;
    string output = testing::internal::GetCapturedStdout();
    return output;
}
