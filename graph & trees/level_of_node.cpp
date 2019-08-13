int levels(struct Node *root,int target,int c){
  if (root == NULL) {
            return 0;
        }
        if (root->data == target) {
            return c;
        }
        int l =levels(root->left, target, c + 1);
        int r =levels(root->right, target, c + 1);
        if (l != 0 ) {
            return l;
        }
        if (r != 0) {
            return r;
        }
        return 0;
    }

