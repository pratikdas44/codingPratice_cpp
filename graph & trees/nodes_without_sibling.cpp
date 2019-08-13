void printSingles(struct node *root)
{   vector<int> v;
	// Base case
	if (root == NULL)
	return;

	// If this is an internal node, recur for left
	// and right subtrees
	if (root->left != NULL && root->right != NULL)
	{
		printSingles(root->left);
		printSingles(root->right);
	}

	// If left child is NULL and right is not, print right child
	// and recur for right child
	else if (root->right != NULL)
	{
		v.push_back(root->right->data);
		printSingles(root->right);
	}

	// If right child is NULL and left is not, print left child
	// and recur for left child
	else if (root->left != NULL)
	{
		v.push_back(root->left->data);
		printSingles(root->left);
	}

	sort(v.begin(),v.end());
	for(int i:v)
	  cout << i << " ";
}