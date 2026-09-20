class Solution {
public:
    int arrangeCoins(int n) {
        int i=1;
        while(n>0)
        {
            if(n>=i)
            {
                n-=i;
                i++;
            }
            else 
                break;
        }
        return i-1;
    }
};