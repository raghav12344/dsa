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
    int height(TreeNode *root)
    {
        if(root==NULL)
            return 0;
        return(max(height(root->left),height(root->right))+1);
    }
    void dfs(TreeNode *root,vector<vector<int>> &res,int level)
    {   
        if(root==NULL)
            return;
        res[level].push_back(root->val);
        
        dfs(root->left,res,level+1);
        dfs(root->right,res,level+1);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res(height(root));
        dfs(root,res,0);
        for(int i=1;i<res.size();i+=2)
        {
            reverse(res[i].begin(),res[i].end());
        }
        return res;
    }
};