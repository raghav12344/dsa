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
    // vector<int> preorderTraversal(TreeNode* root) {
    //     vector<int>arr;
    //     travel(root,arr);
    //     return arr;
    // }
    // void travel(TreeNode *root,vector<int>&arr)
    // {
    //     if(root==NULL)
    //         return;
    //     arr.push_back(root->val);
    //     travel(root->left,arr);
    //     travel(root->right,arr);
    // }
    
    //without recurssion
    vector<int> preorderTraversal(TreeNode* root)
    {
        vector <int> v;
        if(root==NULL)
            return v;
        stack <TreeNode *> s;
        s.push(root);
        while(!s.empty())
        {
            TreeNode *ptr=s.top();
            s.pop();
            v.push_back(ptr->val);
            
            if(ptr->right)
                s.push(ptr->right);
            if(ptr->left)
                s.push(ptr->left);
        }
        return v;
    }
};