class Solution {
public:
    int n,m;
    bool isSafe(int i,int j)
    {
        return i>=0 && i<n && j>=0 && j<m;
    }
    long long recur(vector<vector<int>> &grid,vector<vector<bool>> &vis,int i,int j)
    {
        if(!isSafe(i,j))
            return 0;
        if(vis[i][j]==true)
            return 0;
        if(grid[i][j]==0)
            return 0;
        vis[i][j]=true;
        return (long long)(grid[i][j]+recur(grid,vis,i+1,j)+recur(grid,vis,i-1,j)+recur(grid,vis,i,j+1)+recur(grid,vis,i,j-1));

    }
    int countIslands(vector<vector<int>>& grid, int k) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]!=0 && vis[i][j]==false)
                {
                    long long sum=recur(grid,vis,i,j);
                    if(sum%k==0)
                        count++;
                }
            }
        }
        return count;
    }
};