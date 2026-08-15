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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)
            return NULL;
        if(key<root->val)
            root->left=deleteNode(root->left,key);
        else if(key>root->val)
            root->right=deleteNode(root->right,key);
        else
        {
            if(root->left==NULL && root->right==NULL)
                return NULL;
            else if(root->left==NULL && root->right!=NULL)
                return root->right;
            else if(root->left!=NULL && root->right==NULL)
                return root->left;
            else
            {
                TreeNode *ptr=root->left;
                while(ptr->right!=NULL)
                    ptr=ptr->right;
                root->val=ptr->val;
                root->left=deleteNode(root->left,ptr->val);
            }
        }
        return root;
    }
};