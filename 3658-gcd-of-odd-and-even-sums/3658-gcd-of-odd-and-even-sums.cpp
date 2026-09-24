class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int e=0;
        int o=0;

        for(int i=0;i<=2*n;i++)
        {
            if(i%2==0)
                e+=i;
            else
                o+=i;
        }

        return __gcd(o,e);
    }
};