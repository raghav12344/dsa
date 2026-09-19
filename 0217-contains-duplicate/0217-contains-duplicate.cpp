class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int> mp;
        for(auto v:nums)
            mp[v]++;
        
        for(auto pr:mp)
            if(pr.second>1)
                return true;
        return false;
    }
};