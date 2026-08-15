/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;

        int left_height = 0;
        TreeNode* curr = root;
        while (curr) {
            left_height++;
            curr = curr->left;
        }

        int right_height = 0;
        curr = root;
        while (curr) {
            right_height++;
            curr = curr->right;
        }
        if (left_height == right_height) {
            return (1 << left_height) - 1; 
        }

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};