//inorder traversal is used here. As inorder traversal produces sorted list
//also remember try to include all true or false cases in if statements and
//one else then include true condition.
int compare(Node *root,int *prev){
    if(!root) return 1;
    if(!compare(root->left,prev)) return 0;
    if(root->data < *prev) return 0;
    *prev = root->data;
    return compare(root->right,prev);
}
bool isBST(Node* root) {int prev = INT_MIN;
   return compare(root,&prev);
}


or
int isbstutil(root,int min,int maux){
	if(!root) return 1;
	return(root->data > min && root->data < maux && isbstutil(root->left,min,root->data)
		&& isbstutil(root->right,root->data,maux));
}