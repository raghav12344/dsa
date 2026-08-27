class Solution {
public:
    bool isSafe(int x,int y,int n,int m)
    {
        return (x>=0 && x<n && y>=0 && y<m);
    }
    // vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    //     int n=mat.size();
    //     int m=mat[0].size();
    //     queue<pair<int,int>> q;
    //     vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
    //     for(int i=0;i<n;i++)
    //     {
    //         for(int j=0;j<m;j++)
    //         {
    //             if(mat[i][j]==0)
    //             {
    //                 dist[i][j]=0;
    //                 q.push({i,j});
    //             }
    //         }
    //     }
    //     while(!q.empty())
    //     {
    //         int len=q.size();

    //         for(int i=0;i<len;i++)
    //         {
    //             int x=q.front().first;
    //             int y=q.front().second;
    //             q.pop();
    //             vector<vector<int>> directions={{0,-1},{0,1},{-1,0},{1,0}};

    //             for(int j=0;j<4;j++)
    //             {
    //                 int dx=directions[j][0];
    //                 int dy=directions[j][1];
    //                 if(isSafe(x+dx,y+dy,n,m) && dist[x+dx][y+dy]==INT_MAX)
    //                 {
    //                     dist[x+dx][y+dy]=dist[x][y]+1;
    //                     q.push({x+dx,y+dy});
    //                 }
    //             }
    //         }
    //     }
    //     return dist;
    // }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));

        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(mat[i][j]==0)
                    dist[i][j]=0;
                
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(mat[i][j]==1)
                {
                    if(i>0 && dist[i-1][j]!=INT_MAX)
                        dist[i][j]=min(dist[i][j],dist[i-1][j]+1);
                    if(j>0 && dist[i][j-1]!=INT_MAX)
                        dist[i][j]=min(dist[i][j],dist[i][j-1]+1);
                }   
            

        for(int i=n-1;i>=0;i--)
            for(int j=m-1;j>=0;j--)
                if(mat[i][j]==1)
                {
                    if(i+1<n && dist[i+1][j]!=INT_MAX)
                        dist[i][j]=min(dist[i][j],dist[i+1][j]+1);
                    if(j+1<m && dist[i][j+1]!=INT_MAX)
                        dist[i][j]=min(dist[i][j],dist[i][j+1]+1);
                }

        return dist;
    }
};