//to find tree height
if (node==NULL)  
       return 0; 
   else 
   { 
       /* compute the depth of each subtree */
       int lDepth = maxDepth(node->left); 
       int rDepth = maxDepth(node->right); 
  
       /* use the larger one */
       if (lDepth > rDepth)  
           return(lDepth+1); 
       else return(rDepth+1); 
   } 
void BinaryTree2DoubleLinkedList(node *root, node **head) 
{ 
    // Base case 
    if (root == NULL) return; 
  
    // Initialize previously visited node as NULL. This is 
    // static so that the same value is accessible in all recursive 
    // calls 
    static node* prev = NULL; 
  
    // Recursively convert left subtree 
    BinaryTree2DoubleLinkedList(root->left, head); 
  
    // Now convert this node 
    if (prev == NULL) 
        *head = root; 
    else
    { 
        root->left = prev; 
        prev->right = root; 
    } 
    prev = root; 
  
    // Finally convert right subtree 
    BinaryTree2DoubleLinkedList(root->right, head); 
} 