class Solution {
public:
    vector<int> constructRectangle(int area) {
        int diff=INT_MAX,i,j;
        for(int w=1;w<=sqrt(area);w++)
        {
            int l=area/w;
            int x=l-w;
            if(diff>x && l*w==area)
            {
                diff=x;
                i=l;
                j=w;
            }
        }
        return {i,j};
    }
};