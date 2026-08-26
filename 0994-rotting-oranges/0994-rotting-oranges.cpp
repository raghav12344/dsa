class Solution {
public:
    bool isSafe(int i,int j,int n,int m)
    {
        return(i>=0 && i<n && j>=0 && j<m);
    }
    void dfs(vector<vector<int>> &grid,int i,int j,int time)
    {
        int n=grid.size();
        int m=grid[0].size();

        grid[i][j]=time;

        vector<vector<int>> directions={{0,1},{0,-1},{1,0},{-1,0}};

        for(auto dir:directions)
        {
            int x=i+dir[0];
            int y=j+dir[1];

            if((isSafe(x,y,n,m)) && (grid[x][y]==1 || grid[x][y]>time+1))
                dfs(grid,x,y,time+1);
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        int time=0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                    dfs(grid,i,j,2);
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                    return -1;

                time=max(time,grid[i][j]-2);
            }
        }
        return time;
    }
};