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
    bool chk(TreeNode * r1,TreeNode *r2)
    {
        if(r1==NULL && r2==NULL)
            return true;
        else if(r1==NULL && r2!=NULL)
            return false;
        else if(r2==NULL && r1!=NULL)
            return false;
        else if(r1->val!=r2->val)
            return false;
        return (chk(r1->left,r2->right) && chk(r2->left,r1->right));
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;
        return chk(root->left,root->right);
    }
};