//
// Created by Neptune on 5/8/16.
//

/*
 * Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.
 *
 * According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and
 * w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of
 * itself).”
 */

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) { }
};

class Solution {
  public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (!root)
            return nullptr;

        int val = root->val;

        if (val < p->val && val < q->val)
            return lowestCommonAncestor(root->right, p, q);
        else if (val > p->val && val > q->val)
            return lowestCommonAncestor(root->left, p, q);
        else
            return root;
    }
};

int main() {
    TreeNode *t = new TreeNode(2);
    t->left = new TreeNode(1);
    t->right = new TreeNode(3);
    auto res = Solution().lowestCommonAncestor(t, t->right, t->left);
    cout << res->val << endl;
    return 0;
}
