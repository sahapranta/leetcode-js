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
    string result = "";

    void dfs(TreeNode* root, string curr) {
        if (!root)
            return;

        curr = char(root->val + 'a') + curr;

        if (!root->left && !root->right) {
            if (result == "" || result > curr) {
                result = curr;
            }
        }

        dfs(root->left, curr);
        dfs(root->right, curr);
    }

    string smallestFromLeaf(TreeNode* root) {
        // dfs(root, "");

        // bfs approach
        queue<pair<TreeNode*, string>> que;
        que.push({root, string(1, char(root->val + 'a'))});

        while (!que.empty()) {
            auto [node, curr] = que.front();
            que.pop();

            if (!node->left && !node->right) {
                if (result == "" || result > curr) {
                    result = curr;
                }
            }

            if (node->left) {
                que.push({node->left, char(node->left->val + 'a') + curr});
            }

            if (node->right) {
                que.push({node->right, char(node->right->val + 'a') + curr});
            }
        }

        return result;
    }
};
