class Solution {
public:
    int minRange(int a, int b, int c) {
        int x=min({a,b,c}),z=max({a,b,c});
        int y=a+b+c-z-x;
        return min(z-x,y);
    }
};