class Solution {
public:
    long long countCommas(long long n) {
        long long p=1000;
        long long res=0;
        while(p<=n)
        {
            res+=(n-p+1);
            p*=1000;
        }
        return res;
    }
};