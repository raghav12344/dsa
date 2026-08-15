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
    // vector<int> inorderTraversal(TreeNode* root) {
    //     vector<int>arr;
    //     travel(root,arr);
    //     return arr;
    // }
    // void travel(TreeNode *root,vector<int>&arr)
    // {
    //     if(root==NULL)
    //         return;
    //     travel(root->left,arr);
    //     arr.push_back(root->val);
    //     travel(root->right,arr);
    // }

    //without reccursion
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector <int> v;
        
        stack <TreeNode *> s;
        while(root!=NULL||!s.empty())
        {
            while(root!=NULL)
            {
                s.push(root);
                root=root->left;
            }
            root=s.top();
            s.pop();
            v.push_back(root->val);
            root=root->right;
        }
        return v;
    }

};