class Solution {
public:
    int pivotInteger(int n) {
        long long sum=1LL*n*(n+1)/2;
        long long x=sqrt(sum);

        if(x*x==sum)
            return x;
        return -1;
    }
};