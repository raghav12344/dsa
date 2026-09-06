class Solution {
public:
    long long func(string &s,string &t,int n,int m,vector<vector<long long>> &dp)
    {
        if(m==0)
            return 1;
        if(n==0)
            return 0;
        if(dp[n][m]!=-1)
            return dp[n][m];
        if(s[n-1]==t[m-1])
            return dp[n][m]=func(s,t,n-1,m-1,dp)+func(s,t,n-1,m,dp);
        else
            return dp[n][m]=func(s,t,n-1,m,dp);
    }
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<long long>> dp(n+1,vector<long long>(m+1,-1));
        return func(s,t,n,m,dp);
    }
};