class Solution {
public:
    long long mod=1000000007;
    long long power(long long base,long long exp)
    {
        long long ans=1;
        while(exp>0)
        {
            if(exp%2==1)
                ans=(ans*base)%mod;
            base=(base*base)%mod;
            exp=exp/2;
        }
        return ans;
    }
    int countGoodNumbers(long long n) {
        long long p=n/2;

        if(n%2==0)
            return power(20,p);
        else 
            return (power(20,p)*5)%mod;
    }
};