// If you change anything in this file, your changes will be ignored 
// in your homework submission.
// Chekout TEST_F functions bellow to learn what is being tested.
#include <gtest/gtest.h>
#include "../code_1/Graph.hpp"

#include <fstream>
#include <iostream>
#include <string>
#include <cmath>
#include <array>
#include <vector>
#include "test_helpers.hpp"

using namespace std;

class test_x : public ::testing::Test {
protected:
	// This function runs only once before any TEST_F function
	static void SetUpTestCase(){
		std::ofstream outgrade("./total_grade.txt");
		if(outgrade.is_open()){
			outgrade.clear();
			outgrade << (int)0;
			outgrade.close();
		}
	}

	// This function runs after all TEST_F functions have been executed
	static void TearDownTestCase(){
		std::ofstream outgrade("./total_grade.txt");
		if(outgrade.is_open()){
			outgrade.clear();
			outgrade << (int)std::ceil(100*total_grade/max_grade);
			outgrade.close();
			std::cout << "Total Grade is : " << (int)std::ceil(total_grade)
					  << "/" << max_grade << std::endl;
		}
	}

	void add_points_to_grade(double points){
		if(!::testing::Test::HasFailure()){
			total_grade += points;
		}
	}

	// this function runs before every TEST_F function
	void SetUp() override {}

	// this function runs after every TEST_F function
	void TearDown() override {
		std::ofstream outgrade("./total_grade.txt");
		if(outgrade.is_open()){
			outgrade.clear();
			outgrade << (int)std::ceil(100*total_grade/max_grade);
			outgrade.close();
		}
	}
	
	static double total_grade;
	static double max_grade;
};

double test_x::total_grade = 0;
double test_x::max_grade = 50;




/////////////////////////////////////////
// Tests start here
/////////////////////////////////////////

TEST_F(test_x, TestPrintFurthestNodes){
	string result, expected, start;
	int noVertices, noEdges;
	// TEST 1

	// Graph Vertices and edges
	noVertices = 8;
	noEdges = 7;
    string graph_vertices0[] = {"A","B","C","D","E","F","G","H"};
	// Note that the two arrays are to be treated as pairs
	// i.e. edge between vertices A and B; edge between vertices A and C; etc. 
	string edgesA_0[] = {"A", "A", "C", "B", "D", "E", "G"};
	string edgesB_0[] = {"B", "C", "D", "E", "E", "F", "H"};

	// Test 1A
	start = "A";
	result = test_printFurthest(graph_vertices0, noVertices, edgesA_0, edgesB_0, noEdges, start);
    expected= "F ";
	ASSERT_EQ(expected, result);
	add_points_to_grade(10);

	// Test 1B
	start = "E";
	result = test_printFurthest(graph_vertices0, noVertices, edgesA_0, edgesB_0, noEdges, start);
	expected = "A C ";
	ASSERT_EQ(expected, result);
	add_points_to_grade(10);
	
	// Test 1C
	start = "G";
	result = test_printFurthest(graph_vertices0, noVertices, edgesA_0, edgesB_0, noEdges, start);
	expected = "H ";
	ASSERT_EQ(expected, result);
	add_points_to_grade(10);


	/* --------------------------------------------------------------- */

	// TEST 2
	noVertices = 3;
	noEdges = 3;
	string graph_vertices1[] = {"A","B","C"};
	string edgesA_1[] = {"A", "B", "C"};
	string edgesB_1[] = {"B", "C", "A"};

	// Test 2A
	start = "A";
	result = test_printFurthest(graph_vertices1, noVertices, edgesA_1, edgesB_1, noEdges, start);
    expected= "B C ";
	ASSERT_EQ(expected, result);
	add_points_to_grade(10);

	// Test 2B
	start = "C";
	result = test_printFurthest(graph_vertices1, noVertices, edgesA_1, edgesB_1, noEdges, start);
    expected= "A B ";
	ASSERT_EQ(expected, result);
	add_points_to_grade(10);
}

TEST_F(test_x, test_outersum){
    string result;
    string expected;
    
   int arr[]= {20,15,30,10,25,40,11,35};
   int len = 8;
    
    result = test_outersum(arr,len);
    expected = "[GRADER] Adding key:20\n20 has been added\n[GRADER] Adding key:15\n15 has been added\n[GRADER] Adding key:30\n30 has been added\n[GRADER] Adding key:10\n10 has been added\n[GRADER] Adding key:25\n25 has been added\n[GRADER] Adding key:40\n40 has been added\n[GRADER] Adding key:11\n11 has been added\n[GRADER] Adding key:35\n35 has been added\nouter sum=115\n";
    ASSERT_EQ(expected, result);
    add_points_to_grade(10);
    
    
    int arr1[]= {5, 10, 15, 20, 25};
    int len1 = 5;
    
    result = test_outersum(arr1,len1);
    expected = "[GRADER] Adding key:5\n5 has been added\n[GRADER] Adding key:10\n10 has been added\n[GRADER] Adding key:15\n15 has been added\n[GRADER] Adding key:20\n20 has been added\n[GRADER] Adding key:25\n25 has been added\nouter sum=75\n";
    ASSERT_EQ(expected, result);
    add_points_to_grade(10);
    
    
    int arr2[]= {25,20,15,10,5};
    int len2 = 5;
    
    result = test_outersum(arr2,len2);
    expected = "[GRADER] Adding key:25\n25 has been added\n[GRADER] Adding key:20\n20 has been added\n[GRADER] Adding key:15\n15 has been added\n[GRADER] Adding key:10\n10 has been added\n[GRADER] Adding key:5\n5 has been added\nouter sum=75\n";
    ASSERT_EQ(expected, result);
    add_points_to_grade(10);
    
       
    int arr3[]= {};
    int len3 = 0;
    
    result = test_outersum(arr3,len3);
    expected = "outer sum=0\n";
    ASSERT_EQ(expected, result);
    add_points_to_grade(10);
    
     
    int arr4[]= {5};
    int len4 = 1;
    
    result = test_outersum(arr4,len4);
    expected = "[GRADER] Adding key:5\n5 has been added\nouter sum=5\n";
    ASSERT_EQ(expected, result);
    add_points_to_grade(10);
}