class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int,int> mp;
        vector <int> c;
        for(int i=0;i<nums.size();i++)
        {
            int need=target-nums[i];
            if(mp.contains(need))
            {
                c.push_back(mp[need]);
                c.push_back(i);
                break;
            }
            else
            {
                mp[nums[i]]=i;
            }
        }
        return c;
    }
};