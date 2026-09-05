class Solution {
public:
    bool judgeSquareSum(int c) {
        long long l=0;
        long long r=sqrt(c);

        while(l<=r)
        {
            if(l*l + r*r==c)
                return true;
            else if(l*l + r*r<c)
                l++;
            else 
                r--;
        }
        return false;
    }
};