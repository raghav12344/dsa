class Solution {
public:
    long long gcd(long long a,long long b)
    {
        while(b)
        {
            long long temp=a%b;
            a=b;
            b=temp;
        }
        return a;
    }
    long long lcm(long long a,long long b)
    {
        return a/gcd(a,b)*b;
    }
    long long count(long long x,vector<int>& coins)
    {
        int n=coins.size();
        long long ans=0;

        for(int mask=1;mask<(1<<n);mask++)
        {
            long long l=1;
            int bits=0;
            for(int i=0;i<n;i++)
            {
                if(mask&(1<<i))
                {
                    bits++;
                    l=lcm(l,coins[i]);
                    if(l>x)
                        break;
                }
            }
            if(l>x)
                continue;
            if(bits&1)
                ans+=x/l;
            else
                ans-=x/l;
        }
        return ans;
    }
    long long findKthSmallest(vector<int>& coins, int k) {
        sort(coins.begin(),coins.end());
        long long low=1;
        long long high=1LL*coins[0]*k;
        while(low<high)
        {
            long long mid=low+((high-low)/2);

            if(count(mid,coins)>=k)
                high=mid;
            else 
                low=mid+1;
        }
        return low;
    }
};