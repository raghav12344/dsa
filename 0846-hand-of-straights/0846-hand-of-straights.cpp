class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if((hand.size()%groupSize)!=0)
            return false;
        
        unordered_map<int,int> mp;
        for(auto v:hand)
            mp[v]++;

        for(auto v:hand)
        {
            int s=v;
            while(mp[s-1])
            {
                s--;
            }
            while(s<=v)
            {
                while(mp[s])
                {
                    for(int i=s;i<s+groupSize;i++)
                    {
                        if(!mp[i])
                            return false;
                        
                        mp[i]--;
                    }
                }
                s++;
            }
        }
        return true;
    }
};