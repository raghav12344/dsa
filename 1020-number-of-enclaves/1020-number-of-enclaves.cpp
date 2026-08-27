class Solution {
public:
    bool isSafe(int x,int y,int n,int m)
    {
        return (x>=0 && x<n && y>=0 && y<m);
    }
    void fill(int i,int j,vector<vector<int>>& grid)
    {
        if(!isSafe(i,j,grid.size(),grid[0].size()))
            return ;
        
        if(grid[i][j]!=1)
            return ;
        
        grid[i][j]='0';

        fill(i+1,j,grid);
        fill(i-1,j,grid);
        fill(i,j+1,grid);
        fill(i,j-1,grid);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        for(int i=0;i<n;i++)
        {
            if(grid[i][0]==1)
                fill(i,0,grid);
            if(grid[i][m-1]==1)
                fill(i,m-1,grid);
        }
        for(int j=0;j<m;j++)
        {
            if(grid[0][j]==1)
                fill(0,j,grid);
            if(grid[n-1][j]==1)
                fill(n-1,j,grid);
        }
        int count=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(grid[i][j]==1)
                    count++;
        return count;
    }
};