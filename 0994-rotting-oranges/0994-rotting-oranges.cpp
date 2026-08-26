class Solution {
public:
    bool isSafe(int i,int j,int n,int m)
    {
        return (i>=0 && i<n && j>=0 && j<m);
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        queue<pair<int,int>> q;
        int time=0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                    q.push({i,j});
            }
        }
        vector<vector<int>> directions={{0,1},{0,-1},{1,0},{-1,0}};

        while(!q.empty())
        {
            int size=q.size();
            bool flag=false;

            for(int i=0;i<size;i++)
            {
                auto [x,y]=q.front();
                q.pop();

                for(auto dir:directions)
                {
                    int nx=x+dir[0];
                    int ny=y+dir[1];

                    if(isSafe(nx,ny,n,m) && grid[nx][ny]==1)
                    {
                        grid[nx][ny]=2;
                        q.push({nx,ny});
                        flag=true;
                    }
                }
            }
            if(flag)
                time++;
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(grid[i][j]==1)
                    return -1;

        return time;
    }
};