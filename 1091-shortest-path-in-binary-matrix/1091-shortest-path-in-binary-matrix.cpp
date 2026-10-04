class Solution {
public:

    int mn=INT_MAX;
    bool isSafe(vector<vector<int>> &grid,int i,int j)
    {
        return i>=0 && i<grid.size() && j>=0 && j<grid.size();
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1 || grid[grid.size()-1][grid.size()-1]==1)
            return -1;
        
        
        queue<pair<int,int>> q;
        q.push({0,0});

        vector<vector<int>> dist(grid.size(),vector<int>(grid.size(),-1));

        dist[0][0]=1;
        int dx[]={1,1,1,0,0,-1,-1,-1};
        int dy[]={-1,0,1,-1,1,-1,0,1};

        while(!q.empty())
        {
            auto[i,j]=q.front();
            q.pop();

            if(i==grid.size()-1 && j==grid.size()-1)
                return dist[i][j];
            
            for(int k=0;k<8;k++)
            {
                int ni=i+dx[k];
                int nj=j+dy[k];

                if(!isSafe(grid,ni,nj))
                    continue;
                
                if(grid[ni][nj]==1)
                    continue;
                
                if(dist[ni][nj]!=-1)
                    continue;

                dist[ni][nj]=dist[i][j]+1;
                q.push({ni,nj});
            }
        }
        return -1;
    }
};