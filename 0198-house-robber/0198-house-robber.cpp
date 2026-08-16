class Solution {
public:
    // tabulation
    // int rob(vector<int>& nums) {
    //     int n=nums.size();
    //     vector<int> dp(n+1,-1);
    //     if(n>=1)
    //         dp[1]=nums[0];
    //     if(n>=2)
    //         dp[2]=max(nums[0],nums[1]);
    //     for(int i=3;i<=n;i++)
    //     {
    //         dp[i]=max(dp[i-1],nums[i-1]+dp[i-2]);
    //     }
    //     return dp[n];
    // }
    // memoization
    int fun(int n,vector<int> &dp,vector<int>&nums)
    {
        if(n==1)
            return dp[n]=nums[0];
        if(n==2)
            return dp[n]=max(nums[0],nums[1]);
        if(dp[n]!=-1)
            return dp[n];
        return dp[n]=max(fun(n-1,dp,nums),nums[n-1]+fun(n-2,dp,nums));
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,-1);
        fun(n,dp,nums);
        return dp[n];
    }
};