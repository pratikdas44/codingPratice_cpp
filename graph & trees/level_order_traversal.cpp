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