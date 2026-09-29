class Solution {
public:
    bool recur(vector<vector<char>> &grid,int count,int i,int j,vector<vector<vector<int>>> &dp)
    {
        if(i>=grid.size() || j>=grid[0].size())
            return false;

        if(grid[i][j]=='(')
            count++;
        else
            count--;
        if(count<0)
            return false;
        if(i==grid.size()-1 && j==grid[0].size()-1)
        {
            if(count==0)
                return true;
            else 
                return false;
        }
        if(dp[i][j][count]!=-1)
            return dp[i][j][count];
        return dp[i][j][count]=(recur(grid,count,i+1,j,dp) || recur(grid,count,i,j+1,dp));

    }
    bool hasValidPath(vector<vector<char>>& grid) {
        if((grid.size()+grid[0].size()-1)%2!=0)
            return false;
        vector<vector<vector<int>>> dp(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(grid.size()+grid[0].size(),-1)));
        return recur(grid,0,0,0,dp);
    }
};