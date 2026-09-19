class Solution {
public:
    bool checkOverlap(int r, int cx, int cy, int x1, int y1, int x2, int y2) {
        int x=max(x1,min(cx,x2))-cx;
        int y=max(y1,min(cy,y2))-cy;

        return pow(x,2)+pow(y,2)<=pow(r,2);

    }
};