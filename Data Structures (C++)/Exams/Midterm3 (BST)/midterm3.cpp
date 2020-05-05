#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <iostream>

using namespace std;

struct TreeNode
{
	int key;
	TreeNode *leftChild;
	TreeNode *rightChild;
	TreeNode *parent;
};

void inOrderTraversal(TreeNode *node)
{
	if (node)
	{
		inOrderTraversal(node->leftChild);
		cout << node->key << " ";
		inOrderTraversal(node->rightChild);
	}
}

TreeNode* findMinNode(TreeNode* min) {
	while (min->leftChild != NULL) {
		min = min->leftChild;
	}
	return min;
}

TreeNode* findMaxNode(TreeNode* max) {
	while (max->rightChild != NULL) {
		max = max->rightChild;
	}
	return max;
}


void getName() {
	//Type in your name here
	cout << "Enter your name here: ";
}

void replaceMaxWithMin(TreeNode *root)
{

	if(root != NULL)
	{
		TreeNode* min = findMinNode(root);
		TreeNode* max = findMaxNode(root);
		TreeNode* minP = min -> parent;
		TreeNode* maxP = max -> parent;
		
		maxP -> rightChild = min;
		if(min -> rightChild == NULL)
		{
			minP -> leftChild = NULL;
		}
		else
		{
			minP -> leftChild = min -> rightChild;
			min -> rightChild = NULL;
		}
	}
    
}

int main() {
	TreeNode *root = NULL;


	/*
	These are your test cases. You will have to uncomment each of these test cases one at a time while testing your code.
	Test Case 1 has been uncommented for you
	When you are checking for Test Case 2 uncomment ONLY Test case 2 and comment the other testcases
	When you are checking for Test Case 3 uncomment ONLY Test case 3 and comment the other testcases
	*/

	
	cout << "Test Case 1" << endl;
	cout << "Expected Output after exchange: 5 6 8 12 15 16 17 18 19 3" << endl << endl;
	int a[] = { 15, 8, 18, 16, 17, 19, 20, 5, 12, 3, 6 };
	int length = 11;
	

	/*
	cout << "Test Case 2" << endl;
	cout << "Expected Output after exchange: 4 5 6 8 12 15 16 17 18 19 3" << endl << endl;
	int a[] = {15, 8, 18, 16, 17, 19, 20 ,5, 12, 3, 6, 4};
	int length = 12;*/
	


	/*
	cout << "Test Case 3 - Empty tree" << endl;
	cout << "Expected Output after exchange: " << endl << endl;
	int a[1];
	int length=0;*/
	


	//You don't need to change anything with the code that is below this line
	//--------------------------------------------------------------------------------------------
	for (int i = 0; i<length; i++) {
		TreeNode *newnode = new TreeNode;
		newnode->key = a[i];
		newnode->leftChild = NULL;
		newnode->rightChild = NULL;
		newnode->parent = NULL;

		if (root == NULL) {
			root = newnode;
		}
		else {
			TreeNode *temp = root;
			TreeNode *temp2 = NULL;
			while (temp != NULL) {
				temp2 = temp;
				if (temp->key > a[i]) {
					temp = temp->leftChild;
				}
				else {
					temp = temp->rightChild;
				}
			}
			if (a[i] < temp2->key)
			{
				newnode->parent = temp2;
				temp2->leftChild = newnode;
			}
			else
			{
				newnode->parent = temp2;
				temp2->rightChild = newnode;
			}
		}
	}

	cout << "In Order Traversal Before Exchange:" << endl;
	inOrderTraversal(root);
	cout << endl;

	replaceMaxWithMin(root);

	cout << "In Order Traversal After Exchange:" << endl;
	inOrderTraversal(root);
	cout << endl;
	
	return 0;
}
