class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        if(x==0)
            return true;
        int n=x;
        int n1=n;
        long long  rev=0;
        while(n1!=0)
        {
            int r=n1%10;
            rev=rev*10+r;
            n1=n1/10;
        }
        if(n==rev)
            return true;
        else 
            return false;
    }
};