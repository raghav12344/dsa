class Solution {
public:
    struct Info {
        bool isBST;
        int sum;
        int mn;
        int mx;
    };

    int ans = 0;

    Info dfs(TreeNode* root) {
        if (!root)
            return {true, 0, INT_MAX, INT_MIN};

        Info L = dfs(root->left);
        Info R = dfs(root->right);

        if (L.isBST && R.isBST &&
            root->val > L.mx &&
            root->val < R.mn) {

            int currSum = L.sum + R.sum + root->val;
            ans = max(ans, currSum);

            return {
                true,
                currSum,
                min(root->val, L.mn),
                max(root->val, R.mx)
            };
        }

        return {false, 0, INT_MIN, INT_MAX};
    }

    int maxSumBST(TreeNode* root) {
        dfs(root);
        return ans;
    }
};