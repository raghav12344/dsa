class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0)
            return false;
        double x=log2(n)/2.0;

        if(floor(x)==ceil(x))
            return true;
        else 
            return false;
    }
};