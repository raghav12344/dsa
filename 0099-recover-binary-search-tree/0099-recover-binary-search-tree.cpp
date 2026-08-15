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
    vector<TreeNode*>tree;
    void inorder(TreeNode *root)
    {
        if(root==NULL)
            return;
        inorder(root->left);
        tree.push_back(root);
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        vector<TreeNode *> swap;
        for(int i=0;i<tree.size()-1;i++)
        {
            if(tree[i]->val>tree[i+1]->val)
            {
                swap.push_back(tree[i]);
                swap.push_back(tree[i+1]);
            }
        }
        int a=swap[0]->val,b=swap[swap.size()-1]->val;
        swap[0]->val=b;
        swap[swap.size()-1]->val=a;
    }
};