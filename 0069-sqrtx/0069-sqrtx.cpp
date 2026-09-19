class Solution {
public:
    int mySqrt(int x) {
        if(x==0 || x==1)
            return x;
        int s=0;
        int e=x;

        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if((1LL*mid*mid)>1LL*x)
                e=mid-1;
            else if((mid*mid)==x)
                return mid; 
            else 
                s=mid+1;
        }
        return e;
    }
};