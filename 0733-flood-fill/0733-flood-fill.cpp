class Solution {
public:
    bool isSafe(int i,int j,int n,int m)
    {
        return (i>=0 && i<n && j>=0 && j<m);
    }
    void dfs(vector<vector<int>>& image, int sr, int sc, int color,int scolor)
    {
        int n=image.size();
        int m=image[0].size();
        image[sr][sc]=color;
        vector<vector<int>> directions={{0,1},{0,-1},{1,0},{-1,0}};

        for(auto dir:directions)
        {
            int x=sr+dir[0];
            int y=sc+dir[1];

            if(isSafe(x,y,n,m) && scolor==image[x][y])
            {
                dfs(image,x,y,color,scolor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        if(image[sr][sc]==color)
            return image;
        dfs(image,sr,sc,color,image[sr][sc]);
        return image;
    }
};