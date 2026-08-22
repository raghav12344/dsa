class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0;
        int product=1;
        int n1=n;
        while(n1!=0)
        {
            int r=n1%10;
            sum+=r;
            product*=r;
            n1=n1/10;
        }
        return n%(sum+product)==0;
    }
};