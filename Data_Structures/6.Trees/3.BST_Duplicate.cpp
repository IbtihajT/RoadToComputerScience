/* C++ program to find the median of BST in O(n) 
time and O(1) space*/

#include <iostream>
using namespace std;

/* A binary search tree Node has data, pointer 
to left child and a pointer to right child */

struct Node
{
    int val;
    struct Node *left, *right;
};

struct Node *newNode(int data)
{
    struct Node *temp = new Node;
    temp->val = data;
    temp->left = temp->right = NULL;
    return temp;
}

// cur for storing the current count of the value
// and mx for the maximum count of the element which is denoted by node

int cur = 1, mx = 0;
int node;
struct Node *previous = NULL;

// Find the inorder traversal of the BST
void inorder(struct Node *root)
{
    // If root is NULL then return
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    if (previous != NULL)
    {
        // If the previous value is equal to the current value
        // then increase the count
        if (root->val == previous->val)
        {
            cur++;
        }
        // Else initialize the count by 1
        else
        {
            cur = 1;
        }
    }
    // If currrent count is greater than the max count
    // then update the mx value
    if (cur > mx)
    {
        mx = cur;
        node = root->val;
    }
    // Make the current Node as previous
    previous = root;
    inorder(root->right);
}

// Utility function
int findnode(struct Node *root)
{
    inorder(root);
    return node;
}
int main()
{
    /* Let us create following BST 
				6 
				/ \ 
				5	 7 
			/ \ / \ 
			4	 5 7 7 
	*/

    struct Node *root = newNode(6);
    root->left = newNode(5);
    root->right = newNode(7);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(7);
    root->right->right = newNode(7);

    cout << "Node of BST is " << findnode(root) << '\n';
    return 0;
}
