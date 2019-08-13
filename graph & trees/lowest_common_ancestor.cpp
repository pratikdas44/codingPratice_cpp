while(root){
        if(n1 < root->data && n2 < root->data)
            root = root->left;
         else if(n1 > root->data && n2 > root->data)
           root = root->right;
         else 
          break;
    }
    return root;

//or
if(root == NULL)
     return NULL;
  if(root->data == n1 || root->data == n2)
     return root;
  Node *left = lca(root->left,n1,n2);
  Node *right = lca(root->right,n1,n2);
  
  if(left && right) return root;
  
  return(left!=NULL)? left : right;