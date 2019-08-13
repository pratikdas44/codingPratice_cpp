//program to find lowest common ancestor.
//3 cases may occur here : both nodes on right, or on left or on both sides.

Node *lca(Node *root, int v1,int v2) {
		
        if(root == NULL)
         return root;
         if(root->data == v1 || root->data == v2)
           return root;
        Node *l = lca(root->left,v1,v2);
        Node *r = lca(root->right,v1,v2);
        if(l && r)
          return root;
        else
         return(l?l : r);       
     }