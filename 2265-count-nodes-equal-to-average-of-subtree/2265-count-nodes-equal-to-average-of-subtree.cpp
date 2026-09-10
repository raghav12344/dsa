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
    struct data{
        int sum=0;
        int c=0;
    };
    data dfs(TreeNode *root,int &count)
    {
        if(root==NULL)
            return {0,0};

        data l=dfs(root->left,count);
        data r=dfs(root->right,count);

        if((l.sum+r.sum+root->val)/(l.c+r.c+1)==root->val)
            count++;
        
        return{l.sum+r.sum+root->val,l.c+r.c+1};
    }
    int averageOfSubtree(TreeNode* root) {
        int count=0;
        dfs(root,count);
        return count;
    }
};