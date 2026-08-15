class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        unordered_map<int,int> mp;
        for(auto val:nums)
        {
            mp[val]++;
        }
        for(auto pr:mp)
        {
            if(pr.second>(nums.size()/3))
                res.push_back(pr.first);
        }
        return res;
    }
};