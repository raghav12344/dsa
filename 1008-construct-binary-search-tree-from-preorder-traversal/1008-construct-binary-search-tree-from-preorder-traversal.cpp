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
    int findpos(vector<int>& inorder, int val, int strt, int end) {
        for (int j = strt; j <= end; j++)
        {
            if (inorder[j] == val)
            return j;
        }
        return -1;
    }
    TreeNode *consttree(vector<int>& preorder,vector<int>& inorder,int strt,int end,int &i)
    {
        if(strt>end)
            return NULL;
        
        int mid=findpos(inorder,preorder[i],strt,end);

        TreeNode *root=new TreeNode(preorder[i]);
        i++;
        root->left=consttree(preorder,inorder,strt,mid-1,i);
        root->right=consttree(preorder,inorder,mid+1,end,i);
        return root;
        

    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder=preorder;
        sort(inorder.begin(),inorder.end());
        int i=0;
        return consttree(preorder,inorder,0,preorder.size()-1,i);
    }
};