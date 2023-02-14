#include <iostream>
#include "BST.hpp"
using namespace std;
#define COUNT 10
/**
Create a node with key as data
**/

Node* BST:: createNode(int data)
{
    Node* newNode = new Node;
    newNode->key = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

BST::BST()
{
    root= NULL;
}

/**
parameterized constructor. It will create the root and put the data in the root.
**/

BST::BST(int data)
{
    root = createNode(data);
    cout<< "New tree created with "<<data<<endl;
}

/**
Destructor
**/

BST::~BST(){
     destroyNode(root);
}


Node* BST::getRoot(){
    return root;
}

 /**
 This function will destroy the subtree rooted at currNode.
 Think about in what order should you destroy. POSTORDER. or right-left-root
 **/
void BST:: destroyNode(Node *currNode){
     if(currNode!=NULL)
     {
         destroyNode(currNode->left);
         destroyNode(currNode->right);

         delete currNode;
         currNode = NULL;
     }
 }

/*
Prints a binary tree in a 2D fashion.
Note: The image of the tree is left rotated by 90 degrees.
*/
void BST::print2DUtilHelper(Node *currNode, int space)
{
    // Base case
    if (currNode == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtilHelper(currNode->right, space);

    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", currNode->key);

    // Process left child
    print2DUtilHelper(currNode->left, space);
}

void BST::print2DUtil( int space)
{
  print2DUtilHelper(root, space);
}



//---------------------------- INSERT NODE IN THE TREE --------------------------------------

/**
This function will add the data in the tree rooted at currNode.
We will call this function from addNode.
**/

Node* BST:: addNodeHelper(Node* currNode, int data)
{
    if(currNode == NULL){
        return createNode(data);
    }
    else if(currNode->key < data){
        currNode->right = addNodeHelper(currNode->right,data);
    }
    else if(currNode->key > data){
        currNode->left = addNodeHelper(currNode->left,data);
    }
    return currNode;

}


void BST:: addNode(int data)
{
    root = addNodeHelper(root, data);
    cout<<data<<" has been added"<<endl;
}

//-----------------------------------------PRINT TREE (INORDER TRAVERSAL)--------------------------------

/** This function will traverse the tree in-order and print out the node elements.
printTree() function will call this function.
**/

void BST:: printTreeHelper(Node* currNode){
     if(currNode)
     {
        printTreeHelper( currNode->left);
        cout << " "<< currNode->key;
        printTreeHelper( currNode->right);
     }
 }

void BST:: printTree(){
     printTreeHelper(root);
     cout<<endl;
}


// ------ TODO ------

// NOTE: I HAVE DONE TWO METHODS, ONE OF WHICH DIDN'T WORK INITIALLY, BUT I LATER RETROACTIVELY FIXED.  THE COMMENTED OUT CODE
// IS FOR RECURSION.  THE NON-COMMENTED CODE IS FOR ITERATION.

// FUNCTION FOR LEFT RECURSION.
static int recursiveLeftSum(Node * currNode){
    //BASE CASE: NULL RETURNS 0, SINCE THERE IS NO KEY.
    if(currNode == NULL){
        return 0;
    } else {
        //RECURSIVE CASE: ADD THE CURRENT KEY TO THE NEXT VALUE BELOW IT.
        return currNode->key + recursiveLeftSum(currNode->left);
    }
}

// FUNCTION FOR RIGHT RECURSION.
static int recursiveRightSum(Node * currNode){
    //BASE CASE: NULL RETURNS 0, SINCE THERE IS NO KEY.
    if(currNode == NULL){
        return 0;
    } else {
        //RECURSIVE CASE: ADD THE CURRENT KEY TO THE NEXT VALUE BELOW IT.
        return currNode->key + recursiveRightSum(currNode->right);
    }
} 

int BST::outer_sum(){
    // THIS IS THE RECURSIVE IMPLEMENTATION. IT IS COMMENTED OUT BECAUSE I CHOSE THE ITERATIVE SOLUTION.  YOU CAN UNCOMMENT
    // AND VERIFY THAT IT FUNCTIONS, IF THE ITERATIVE SOLUTION IS NOT TO STANDARDS.

    /*
    // IF THE ROOT EQUALS NULL, THEN THE SUM IS 0.
    if (getRoot() == NULL){
        return 0;
    }

    // TO AVOID PROBLEMS WITH THE ROOT IN RECURSION, SET TOTALSUM TO THE ROOT VALUE.
    int totalSum = getRoot()->key;

    // USE THE TWO RECURSIVE METHODS TO OBTAIN THE NECESSARY SUMMATIONS.

    // L RECURSION
    totalSum = totalSum + recursiveLeftSum(getRoot()->left);

    // R RECURSION
    totalSum = totalSum + recursiveRightSum(getRoot()->right);

    // RECURSIVE METHOD ENDS HERE.
    */
    ///*

    // CHECK IF ROOT IS NULL. IF THAT IS THE CASE, THEN RETURN 0.
    if (getRoot() == NULL){
        return 0;
    }

    // SINCE THE ROOT WON'T BE USED IN THE WHILE LOOPS, ACCOUNT FOR IT IN THE ESTABLISHMENT OF THE TOTALSUM VARIABLE
    int totalSum = getRoot()->key;

    // TESTING CODE cout << getRoot()->key << endl;

    // ESTABLISH THE LEFT AND RIGHT NODES FOR LOOP NAVIGATION
    Node * leftNode = getRoot()->left;
    Node * rightNode = getRoot()->right;

    // WHILE THE VALUE OF THE LEFT NODE IS NOT NULL, DO THE FOLLOWING:
    while (leftNode != NULL) {
        // ADD THE LEFT KEY TO THE TOTAL SUM
        totalSum += leftNode->key;

        // ITERATE THE NODE TO THE NEXT OUTERMOST NODE.  THE LOOP WILL STOP WHEN IT EQUALS NULL.
        // TESTING CODE cout << leftNode->key << endl;
        leftNode = leftNode->left;
    }

    // WHILE THE VALUE OF THE RIGHT NODE IS NOT NULL, DO THE FOLLOWING:
    while (rightNode != NULL) {
        // ADD THE RIGHT KEY TO THE TOTAL SUM
        totalSum += rightNode->key;
        // ITERATE THE NODE TO THE NEXT OUTERMOST NODE.  THE LOOP WILL STOP WHEN IT EQUALS NULL.
        // TESTING CODE cout << rightNode->key << endl;
        rightNode = rightNode->right;
    }
    //*/
    //RETURN THE SUMMATION WHEN COMPLETE.
  return totalSum;
}
