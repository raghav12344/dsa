class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
       int n=grid.size();
       int m=grid[0].size();
       int t=m*n;
       k=k%t;
       vector<vector<int>> ans(n,vector<int>(m,0));

       for(int i=0;i<n;i++)
       {
            for(int j=0;j<m;j++)
            {
                int oidx=i*m+j;
                int nidx=(oidx+k)%t;

                int nr=nidx/m;
                int nc=nidx%m;

                ans[nr][nc]=grid[i][j];
            }
       }
        return ans;
    }
};