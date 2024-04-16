/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* add(TreeNode* root, int val, int depth, int cur) {
        if (root == NULL) {
            return NULL;
        }

        if (cur == depth - 1) {
            TreeNode* left = root->left;
            TreeNode* right = root->right;

            root->left = new TreeNode(val);
            root->right = new TreeNode(val);

            root->left->left = left;
            root->right->right = right;

            return root;
        }

        root->left = add(root->left, val, depth, cur + 1);
        root->right = add(root->right, val, depth, cur + 1);

        return root;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        int cur = 1;

        if (depth == cur) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;

            return newRoot;
        }

        return add(root, val, depth, cur);
    }
};
