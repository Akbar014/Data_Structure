/************************************************************

    Following is the TreeNode class structure:

    template <typename T>

    class TreeNode {
    public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;
        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include <bits/stdc++.h>
vector<int> reverseLevelOrder(TreeNode<int> *root) {

    queue<TreeNode<int>*> q;
    // stack<TreeNode<int>*> s;
    vector<int> v;

    if (root)
        q.push(root);

    while (!q.empty()) {
        TreeNode<int>* p = q.front();
        q.pop();

        v.push_back(p->val);

        // Push right child first, then left child
        if (p->left) q.push(p->left);
        if (p->right) q.push(p->right);
        
    }
    reverse(v.begin(),v.end());

    return v;
}