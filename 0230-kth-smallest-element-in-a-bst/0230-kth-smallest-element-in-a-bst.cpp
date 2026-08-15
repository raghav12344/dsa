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
    void dfs(TreeNode * root,int &i,int &k,int &val)
    {
        if(root==NULL)
            return;
        
        dfs(root->left,i,k,val);
        if(i==k)
            val=root->val;
        i++;
        dfs(root->right,i,k,val);


    }
    int kthSmallest(TreeNode* root, int k) {
        int val=0,i=1;
        dfs(root,i,k,val);
        return val;
    }
};