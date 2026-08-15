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
    vector<int> rightSideView(TreeNode* root) {
        vector <int> v;
        if(root==NULL)
            return v;
        queue <TreeNode *> q;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            for(int i=1;i<=n;i++)
            {
                TreeNode *ptr=q.front();
                q.pop();
                if(i==n)
                    v.push_back(ptr->val);
                if(ptr->left!=NULL)
                    q.push(ptr->left);
                if(ptr->right!=NULL)
                    q.push(ptr->right);
            }
        }
        return v;
    }
};