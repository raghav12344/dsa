class Solution {
public:
    bool isSafe(int x,int y,int n,int m)
    {
        return (x>=0 && x<n && y>=0 && y<m);
    }
    void flood(int i,int j,vector<vector<char>>& grid)
    {
        if(!isSafe(i,j,grid.size(),grid[0].size()))
            return;
        if(grid[i][j]!='1')
            return;
        grid[i][j]='0';
        flood(i+1,j,grid);
        flood(i-1,j,grid);
        flood(i,j+1,grid);
        flood(i,j-1,grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        queue<pair<int,int>> q;
        int n=grid.size();
        int m=grid[0].size();

        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(grid[i][j]=='1')
                    q.push({i,j});
        int count=0;
        while(!q.empty())
        {
            auto[x,y]=q.front();
            q.pop();

            if(grid[x][y]=='1')
            {
                count++;
                flood(x,y,grid);
            }

        }
        return count;
    }
};