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
    // void dfs(TreeNode *root,vector<int>&arr,int k,bool &res)
    // {
    //     if(root==NULL)
    //         return;
        
    //     dfs(root->left,arr,k,res);
    //     dfs(root->right,arr,k,res);
    //     if(find(arr.begin(),arr.end(),root->val)!=arr.end())
    //         res=true;
    //     arr.push_back(k-(root->val));

    // }
    // bool findTarget(TreeNode* root, int k) {
    //     bool res=false;
    //     vector<int> arr;
    //     dfs(root,arr,k,res);
    //     return res;
    // }

    // using set
    bool dfs(TreeNode* root, int k,unordered_set<int> &s )
    {
        if(root==NULL)
            return false;
        if(s.count(k-root->val))
            return true;
        s.insert(root->val);
        return dfs(root->left,k,s) || dfs(root->right,k,s);
    }
    bool findTarget(TreeNode* root, int k)
    {
        unordered_set<int> s;
        return dfs(root,k,s);
    }
};