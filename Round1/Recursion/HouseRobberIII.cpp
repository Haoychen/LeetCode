/*
The thief has found himself a new place for his thievery again. There is only 
one entrance to this area, called the "root." Besides the root, each house has 
one and only one parent house. After a tour, the smart thief realized that "all 
houses in this place forms a binary tree". It will automatically contact the 
police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting
the police.

Example 1:
     3
    / \
   2   3
    \   \ 
     3   1
Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
Example 2:
     3
    / \
   4   5
  / \   \ 
 1   3   1
Maximum amount of money the thief can rob = 4 + 5 = 9.
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int rob(TreeNode* root) {
        if (!root) return 0;
        int res = 0;
        if (root->left && root->right) {
            res = max(root->val + rob(root->left->left) + rob(root->left->right)
                + rob(root->right->left) + rob(root->right->right), rob(root->left)
                + rob(root->right));
        }
        else if (root->left) {
            res = max(root->val + rob(root->left->left) + rob(root->left->right),
                    rob(root->left));
        }
        else if (root->right) {
            res = max(root->val + rob(root->right->left) + rob(root->right->right),
                    rob(root->right));
        }
        else {
            return root->val;
        }
        return res;
    }
};
