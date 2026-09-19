class Solution {
public:
    bool isPerfectSquare(int n) {
        if(n<2)
            return true;
        int s=0;
        int e=n/2;
        while(s<=e)
        {
            int mid=s+(e-s)/2;

            if((long long)mid*mid==(long long)n)
                return true;
            else if((long long)mid*mid<(long long)n)
                s=mid+1;
            else    
                e=mid-1;
        }
        return false;
    }
};