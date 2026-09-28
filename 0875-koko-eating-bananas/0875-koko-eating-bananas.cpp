class Solution {
public:
    bool chk(int k,vector<int> &piles,int h)
    {
        int i=0;
        while(h>0 && i<piles.size())
        {
            if(piles[i]<=k)
            {
                h--;
                i++;
            }
            else 
            {
                h=h-ceil(1.0*piles[i]/k);
                i++;
            }
        }
        return i==piles.size() && h>=0;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int hi=*max_element(piles.begin(),piles.end());

        int lo=1;
        int ans=0;
        while(lo<=hi)
        {
            int mid=lo+(hi-lo)/2;
            if(chk(mid,piles,h))
            {
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;
    }
};