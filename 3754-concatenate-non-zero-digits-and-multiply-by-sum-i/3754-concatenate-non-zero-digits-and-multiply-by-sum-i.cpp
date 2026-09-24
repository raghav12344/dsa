class Solution {
public:
    long long sumAndMultiply(int n) {
        int rev=0;
        while(n!=0)
        {
            int r=n%10;
            if(r!=0)
                rev=rev*10+r;
            n=n/10;
        }
        int n1=0;
        int sum=0;
        while(rev!=0)
        {
            int r=rev%10;
            n1=n1*10+r;
            rev=rev/10;
            sum+=r;
        }
        return 1LL*sum*n1;

    }
};