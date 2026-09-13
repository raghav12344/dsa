class Solution {
public:
    int convolute(vector<vector<int>>& img1, vector<vector<int>>& b_padded,int xs,int ys)
    {
        int res=0;
        for(int r=0;r<img1.size();r++)
        {
            for(int c=0;c<img1.size();c++)
            {
                res+=img1[r][c]*b_padded[r+xs][c+ys];
            }
        }
        return res;
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();

        vector<vector<int>> b_padded(3*n-2,vector<int>(3*n-2,0));

        for(int r=0;r<n;r++)
            for(int c=0;c<n;c++)
                b_padded[r+n-1][c+n-1]=img2[r][c];
        
        int mx=0;
        for(int xs=0;xs<2*n-1;xs++)
        {
            for(int ys=0;ys<2*n-1;ys++)
            {
                mx=max(mx,convolute(img1,b_padded,xs,ys));
            }
        }
        return mx;
    }
};