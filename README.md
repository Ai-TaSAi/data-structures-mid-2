# Data Structures Coding Problem

**IMPORTANT: Only second coding problem was attempted.**

## Problem 1
Given an implementation of an undirected and unweighted graph class `Graph.cpp, Graph.hpp`, implement a member function that, for a given source vertex, prints the keys of all vertices whose shortest distance from the source vertex is maximum amongst all vertices that can be reached from the source vertex. 

### Specifications
Function prototype:

``
void printFurthestNodes(string source_name);
``
where `source_name` is the name of the starting vertex.

### Example
Consider the following graph: 

<img src="./images/graph.png" width="600">

A call to `printFurthestNodes("A")` should print:

```
 F
```

Similarly, a call to `printFurthestNodes("E")` should print:

```
 A, C
```
## Problem 2
In this problem you will write a function to sum up all the nodes on the outer periphery of a binary tree.

### Specifications
 1. The function definition is given by
 ```
    int BST::outer_sum()
    Note: root is a private member of BST class.
 ```

 2. Your implementation can be either recursive or iterative. 
 3. Do not change the hpp file. In the cpp file you can use helper function(s) if you desire.

### Example
Consider the following tree: 

<img src="./images/tree.png" width="600">

A call to `outer_sum()` should return:

```
115
```
NOTE: It is construed as  (10 +15 + 20 + 30 + 40). Right-child of 10 is not  included. Because being left side of the tree the node 11 is not at outermost periphery.  Similarly left child of 40 is not included.






##  Instructions - Getting and submitting code

 1. Open up your Linux terminal, navigate to the build directory of this assignment (e.g. `cd build`).
 2. Run the `cmake ..` command.
 3. Run the `make` command.
 4. If there are no compilation errors, two executables will be generated within the build directory: `run_app_1` and `run_tests`.
 5. If you would like to run your program including your app implementation in the `main` function, execute `run_app_1` from the terminal by typing `./run_app_1`.
 6. To run the grading tests, execute `run_tests` from the terminal by typing `./run_tests`. 
