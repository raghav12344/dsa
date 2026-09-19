class Solution {
public:
    int count(int n)
    {
        int c=0;
        while(n!=0)
        {
            n=n/10;
            c++;
        }
        return c;
    }
    int sum(int n)
    {
        int s=0;
        while(n!=0)
        {
            int r=n%10;
            s+=r;
            n/=10;
        }
        return s;
    }
    int addDigits(int num) {
        while(count(num)>1)
        {
            num=sum(num);
        }
        return num;
    }
};