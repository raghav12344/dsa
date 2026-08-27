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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> res;
        if(root==NULL)
            return res;
        while(!q.empty())
        {
            int sz=q.size();
            vector<int> temp;

            for(int i=0;i<sz;i++)
            {
                TreeNode *ptr=q.front();
                q.pop();

                if(ptr!=NULL && ptr->left!=NULL)
                    q.push(ptr->left);
                if(ptr!=NULL && ptr->right!=NULL)
                    q.push(ptr->right);
                if(ptr!=NULL)
                    temp.push_back(ptr->val);
            }
            res.push_back(temp);

        }
        return res;
    }
};