class Solution {
public:
    int sum(int n)
    {
        int res=0;
        while(n!=0)
        {
            int r=n%10;
            res+=pow(r,2);
            n/=10;
        }
        return res;
    }
    bool isHappy(int n) {
        int n1=n;
        for(int i=0;i<2*sqrt(n);i++)
        {
            int res=sum(n);
            if(res==1)
                return true;
            n=res;
        }
        return false;
    }
};