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
    bool isValidBST(TreeNode* root) {
        vector<int> tree;
        arr(tree,root);
        for(int i=0;i<tree.size()-1;i++)
        {
            if(tree[i]>=tree[i+1])
                return false;
        }
        return true;
    }
    void arr(vector<int>&tree,TreeNode *root)
    {
        if(root==NULL)
            return;
        arr(tree,root->left);
        tree.push_back(root->val);
        arr(tree,root->right);
    }
};