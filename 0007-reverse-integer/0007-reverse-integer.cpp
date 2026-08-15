class Solution {
public:
    int reverse(int n){
        int rev=0;
        while(n!=0)
        {
            int r=n%10;
            if((rev>INT_MAX/10 || rev==INT_MAX/10 && r>7)||(rev<INT_MIN/10 || rev==INT_MIN/10 && r<-8))
                return 0;
            else
                rev=rev*10+r;
            n=n/10;
        }
        return rev;
    }
};