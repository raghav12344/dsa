class Solution {
public:
    int count(int n)
    {
        int count=0;
        for(int i=0;i<=31;i++)
        {
            if((n&1)==1)
                count++;
            n>>=1;
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int> res;
        for(int i=0;i<=n;i++)
            res.push_back(count(i));
        
        return res;
    }
};