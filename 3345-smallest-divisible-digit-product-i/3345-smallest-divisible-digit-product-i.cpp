class Solution {
public:
    int product(int n)
    {
        int p=1;
        while(n!=0)
        {
            int r=n%10;
            n=n/10;
            p*=r;
        }
        return p;
    }
    int smallestNumber(int n, int t) {
        while(1)
        {
            if(product(n)%t==0)
                return n;
            n++;
        }
    }
};