//target is node data item
bool printAncestors1(Node*root,int target)
{
    if(root==NULL)return false;
    if(root->data==target)return true;
    if(printAncestors1(root->left,target)||printAncestors1(root->right,target))
    {
            cout<<root->data<<" ";
            return true;
    }
    return false;
}
bool printAncestors(struct Node *root, int target)
{
   bool res=printAncestors1(root,target);
   cout<<endl;
   return res;
}