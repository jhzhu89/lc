//
// Created by Neptune on 5/9/16.
//

/*
 * Given a binary tree
 *
 *
 *      struct TreeLinkNode {
 *          TreeLinkNode *left;
 *          TreeLinkNode *right;
 *          TreeLinkNode *next;
 *      }
 *
 * Populate each next pointer to point to its next right node. If there is no next right node, the next pointer
 * should be set to NULL.
 *
 * Initially, all next pointers are set to NULL.
 *
 * Note:
 *
 *      You may only use constant extra space.
 *      You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent
 *      has two children).
 *
 * For example,
 *      Given the following perfect binary tree,
 *
 *              1
 *             /  \
 *            2    3
 *           / \  / \
 *          4  5  6  7
 *
 * After calling your function, the tree should look like:
 *
 *              1 -> NULL
 *             /  \
 *            2 -> 3 -> NULL
 *           / \  / \
 *          4->5->6->7 -> NULL
 */

#include <queue>

using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) { }
};

class Solution {
  public:
    void connect(TreeLinkNode *root) {
        if (!root) return;

        root->next = nullptr;

        while (root->left) {
            auto ptr = root;

            while (ptr) {
                ptr->left->next = ptr->right;
                ptr->right->next = ptr->next ? ptr->next->left : nullptr;
                ptr = ptr->next;
            }

            root = root->left;
        }
    }
};

int main() {
    TreeLinkNode *t = new TreeLinkNode(1);
    t->left = new TreeLinkNode(2);
    t->right = new TreeLinkNode(3);
    Solution().connect(t);
    return 0;
}
