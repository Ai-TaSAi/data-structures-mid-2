#ifndef TEST_H__
#define TEST_H__
#include <string>
#include <iostream>
#include <fstream>
#include <array>

using namespace std;

// TODO add detailed explanation on what the function should do
std::string exec(const char* cmd);
std::string readFileIntoString(std::string fileName);
std::string test_printFurthest(string* vertices,  int noVertices, string *edgesA, 
                                string *edgesB, int noEdges, string startVertex);
string test_outersum(int keys[], int len);


#endif // TEST_H__