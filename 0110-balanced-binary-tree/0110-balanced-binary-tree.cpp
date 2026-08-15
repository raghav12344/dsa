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
    // int height(TreeNode *root)
    // {
    //     if(root==NULL)
    //         return 0;
    //     int x=height(root->left)+1;
    //     int y=height(root->right)+1;

    //     return max(x,y);
    // }
    // bool isBalanced(TreeNode* root) {
    //     if(root==NULL)
    //         return true;
        
    //     int hx=height(root->left);
    //     int hy=height(root->right);

    //     if(isBalanced(root->left) && isBalanced(root->right))
    //     {
    //         if(abs(hx-hy)<=1)
    //             return true;
    //         else
    //             return false;
    //     }
    //     else    
    //         return false;
    // }

    int chk(TreeNode *root)
    {
        if(root==NULL)
            return 0;
        int x=chk(root->left);
        int y=chk(root->right);

        if(x==-1 || y==-1 || abs(x-y)>1)
            return -1;
        
        return max(x,y)+1;
    }
    bool isBalanced(TreeNode * root)
    {
        return(chk(root)>=0);
    }
};