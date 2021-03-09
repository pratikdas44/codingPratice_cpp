//program to find mirror node of a node
//given parent node index and child nodes index
//**use of constructor in struct (new learning)
#include <bits/stdc++.h>

using namespace std;

 

/* Custom Definitions */

#define ll long long

#define MOD 1000000007

#define pb push_back

 

/* TreeNode */

struct TreeNode {

    int val;

    TreeNode *left, *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} //initializer list

};

 

int findMirror(TreeNode* left, TreeNode* right, int target) {

    if (!left || !right) return 0;

    if (left->val == target)

        return right->val;

    if (right->val == target)

        return left->val;

    int mirrorVal = findMirror(left->left, right->right, target);

    if (mirrorVal) return mirrorVal;

    return findMirror(left->right, right->left, target);

}

int main() {

    #ifndef ONLINE_JUDGE

        freopen("input.txt", "r", stdin);

        freopen("output.txt", "w", stdout);

    #endif

    /* Write your code here */

    int n, q;

    cin >> n >> q;

    map <int, TreeNode*> m;

    m[1] = new TreeNode(1);

    for (int i = 0; i < n - 1; i++) {

        int parent, child;

        char pos;

        cin >> parent >> child >> pos;

        TreeNode* newNode = new TreeNode(child);

        m[child] = newNode;

        if (pos == 'L') {

            m[parent]->left = newNode;

        }

        if (pos == 'R') {

            m[parent]->right = newNode;

        }

    }

    // Finding the mirror of the nodes

    for (int i = 0; i < q; i++) {

        int node; cin >> node;

        if (m[1]->val == node) {cout << node << endl; continue;}

        int ans = findMirror(m[1]->left, m[1]->right, node);

        if (ans == 0) cout << -1 << endl;

        else cout << ans << endl;

    }

    return 0;

}