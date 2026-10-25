class Solution {
public:
    bool isSafe(int i,int j,vector<vector<bool>> &dp)
    {
        int n=dp.size();
        int m=dp[0].size();
        return i>=0 && j>=0 && i<n && j<m;
    }
    bool recur(vector<vector<int>>&grid,vector<vector<bool>>&dp,int i,int j)
    {
        if(!isSafe(i,j,dp))
            return false;
        if(grid[i][j]==1 || dp[i][j])
            return true;
        dp[i][j]=true;
        return dp[i][j]=recur(grid,dp,i+1,j)&&recur(grid,dp,i-1,j)&&recur(grid,dp,i,j+1)&&recur(grid,dp,i,j-1);
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<bool>> dp(n,vector<bool>(m,false));

        recur(grid,dp,0,0);
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0&&dp[i][j]==false)
                {
                    if(recur(grid,dp,i,j))
                    count++;
                }
            }
        }
        return count;
    }
};