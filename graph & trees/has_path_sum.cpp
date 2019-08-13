//sum is given find whether that sum can be obtained by any
//root to leaf path.

        bool hasPathSum(TreeNode *root, int sum) {
            if (root == NULL) return false;
            if (root->left == NULL && root->right == NULL) {
                return sum == root->val;
            }
            int remainingSum = sum - root->val;
            return hasPathSum(root->left, remainingSum) || hasPathSum(root->right, remainingSum);
        }
