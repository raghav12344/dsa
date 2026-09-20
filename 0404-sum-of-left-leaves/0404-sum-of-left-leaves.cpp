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
    void dfs(TreeNode*root,int &sum,bool isleft)
    {
        if(root==NULL)
            return ;
        if(root->left==NULL && root->right==NULL && isleft)
        {
            sum+=root->val;
            return;
        }
        dfs(root->left,sum,true);
        dfs(root->right,sum,false);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum=0;
        dfs(root,sum,false);
        return sum;
    }
};