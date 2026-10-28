class Solution {
public:
    int recur(vector<vector<int>>&grid,vector<vector<vector<int>>>&dp,int i,int j,int temp)
    {
        if(i>=grid.size()||j>=grid[0].size())
            return INT_MAX;
        temp^=grid[i][j];
        if(i==grid.size()-1 && j==grid[0].size()-1)
            return temp;
        
        if(dp[i][j][temp]!=-1)
            return dp[i][j][temp];
        
        int right=recur(grid,dp,i+1,j,temp);
        int down=recur(grid,dp,i,j+1,temp);
        return dp[i][j][temp]=min(right,down);    
    }
    int minCost(vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dp(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(1024,-1)));
        return recur(grid,dp,0,0,0);
    }
};