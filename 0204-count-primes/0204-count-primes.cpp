class Solution {
public:
    int countPrimes(int n) {
        if(n<2)
            return 0;
        int count=n-2;
        vector<char> prime(n,1);
        prime[0]=prime[1]=0;
        for(int p=2;p*p<n;p++)
        {
            if(prime[p])
                for(int i=p*p;i<n;i+=p)
                {
                    if(prime[i])
                    {
                        prime[i]=0;
                        count--;
                    }
                }
        }
        return count;
    }
};