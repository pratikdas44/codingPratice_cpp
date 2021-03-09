//code contains basic tree implementation and Level order traversal.
#include<bits/stdc++.h>
using namespace std;

struct Binarytree{
int data;
struct Binarytree *left;
struct Binarytree *right;
};

struct Binarytree *newnode(int data){
struct Binarytree *node = new Binarytree;
node->left = NULL;
node->right = NULL;
node->data = data;

return node;
}

void Print(struct Binarytree *root){
if (root == NULL)  return;

    // Create an empty queue for level order tarversal
    queue<Binarytree *> q;

    // Enqueue Root and initialize height
    q.push(root);

    while (q.empty() == false)
    {
        // Print front of queue and remove it from queue
        Binarytree *node = q.front();
        cout << node->data << " ";
        q.pop();

        /* Enqueue left child */
        if (node->left != NULL)
            q.push(node->left);

        /*Enqueue right child */
        if (node->right != NULL)
            q.push(node->right);
    }

}

int main(){
struct Binarytree *root = newnode(1);
root->left = newnode(2);
root->right = newnode(4);
root->left->left = newnode(5);
Print(root);
}
 //reverse level order traversal
void findmax(struct node *root){
if(root==NULL) return;
queue<node *>q;
stack<int>s;node *n;
q.push(root);
while(q.empty() == false){
 n = q.front();
 q.pop();
 s.push(n->data);
 if(n->right)
  q.push(n->right);
if(n->left)
  q.push(n->left);
}
while(!s.empty())
  {
    cout << s.top() << " ";
    s.pop();
  }

}
//level order in spiral
void printSpiral(struct node* root) 
{ 
    if (root == NULL) 
        return; // NULL check 
  
    // Create two stacks to store alternate levels 
    stack<struct node*> s1; // For levels to be printed from right to left 
    stack<struct node*> s2; // For levels to be printed from left to right 
  
    // Push first level to first stack 's1' 
    s1.push(root); 
  
    // Keep printing while any of the stacks has some nodes 
    while (!s1.empty() || !s2.empty()) { 
        // Print nodes of current level from s1 and push nodes of 
        // next level to s2 
        while (!s1.empty()) { 
            struct node* temp = s1.top(); 
            s1.pop(); 
            cout << temp->data << " "; 
  
            // Note that is right is pushed before left 
            if (temp->right) 
                s2.push(temp->right); 
            if (temp->left) 
                s2.push(temp->left); 
        } 
  
        // Print nodes of current level from s2 and push nodes of 
        // next level to s1 
        while (!s2.empty()) { 
            struct node* temp = s2.top(); 
            s2.pop(); 
            cout << temp->data << " "; 
  
            // Note that is left is pushed before right 
            if (temp->left) 
                s1.push(temp->left); 
            if (temp->right) 
                s1.push(temp->right); 
        } 
    } 
} 

//spiral order in clockwise
// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 

// Binary tree node 
struct Node { 
    struct Node* left; 
    struct Node* right; 
    int data; 

    Node(int data) 
    { 
        this->data = data; 
        this->left = NULL; 
        this->right = NULL; 
    } 
}; 

// Recursive Function to find height 
// of binary tree 
int height(struct Node* root) 
{ 
    // Base condition 
    if (root == NULL) 
        return 0; 

    // Compute the height of each subtree 
    int lheight = height(root->left); 
    int rheight = height(root->right); 

    // Return the maximum of two 
    return max(1 + lheight, 1 + rheight); 
} 

// Function to Print Nodes from left to right 
void leftToRight(struct Node* root, int level) 
{ 
    if (root == NULL) 
        return; 

    if (level == 1) 
        cout << root->data << " "; 

    else if (level > 1) { 
        leftToRight(root->left, level - 1); 
        leftToRight(root->right, level - 1); 
    } 
} 

// Function to Print Nodes from right to left 
void rightToLeft(struct Node* root, int level) 
{ 
    if (root == NULL) 
        return; 

    if (level == 1) 
        cout << root->data << " "; 

    else if (level > 1) { 
        rightToLeft(root->right, level - 1); 
        rightToLeft(root->left, level - 1); 
    } 
} 

// Function to print clockwise spiral 
// traversal of a binary tree without using 2D array 
void ClockWiseSpiral(struct Node* root) 
{ 
    int i = 1; 
    int j = height(root); 

    // Flag to mark a change in the direction 
    // of printing nodes 
    int flag = 0; 
    while (i <= j) { 

        // If flag is zero print nodes 
        // from left to right 
        if (flag == 0) { 
            leftToRight(root, i); 

            // Set the value of flag as zero 
            // so that nodes are next time 
            // printed from right to left 
            flag = 1; 

            // Increment i 
            i++; 
        } 

        // If flag is one print nodes 
        // from right to left 
        else { 
            rightToLeft(root, j); 

            // Set the value of flag as zero 
            // so that nodes are next time 
            // printed from left to right 
            flag = 0; 

            // Decrement j 
            j--; 
        } 
    } 
} 

// Driver code 
int main() 
{ 
    struct Node* root = new Node(10); 

    root->left = new Node(12); 
    root->right = new Node(13); 

    root->right->left = new Node(14); 
    root->right->right = new Node(15); 

    root->right->left->left = new Node(21); 
    root->right->left->right = new Node(22); 
    root->right->right->left = new Node(23); 
    root->right->right->right = new Node(24); 

    ClockWiseSpiral(root); 

    return 0; 
} 
