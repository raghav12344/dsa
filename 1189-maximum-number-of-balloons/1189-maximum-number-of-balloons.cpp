class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int a=0;
        int b=0;
        int l=0;
        int n=0;
        int o=0;

        for(auto ch:text)
        {
            if(ch=='a')
                a++;
            if(ch=='b')
                b++;
            if(ch=='l')
                l++;
            if(ch=='n')
                n++;
            if(ch=='o')
                o++;
        }
        o=o/2;
        l=l/2;

        return min({a,b,l,n,o});
    }
};