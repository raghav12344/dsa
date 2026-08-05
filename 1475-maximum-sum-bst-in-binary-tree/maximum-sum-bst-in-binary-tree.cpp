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
    struct Info{
        bool isBST;
        int sum;
        int mn;
        int mx;
    };
    int ans=0;
    Info dfs(TreeNode * root)
    {
        if(root==NULL)
            return {true,0,INT_MAX,INT_MIN};
        
        Info l=dfs(root->left);
        Info r=dfs(root->right);

        if(l.isBST && r.isBST && root->val>l.mx && root->val<r.mn )
        {
            ans=max(ans,l.sum+r.sum+root->val);
            return {true,l.sum+r.sum+root->val,min(l.mn,root->val),max(r.mx,root->val)};
        }
        return {false,0,INT_MIN,INT_MAX};
    }
    int maxSumBST(TreeNode* root) {
        ans=0;
        dfs(root);
        return ans;
    }
};