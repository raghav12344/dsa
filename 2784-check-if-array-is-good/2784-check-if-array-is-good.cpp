class Solution {
public:
    bool isGood(vector<int>& nums) {
        vector<int> count(nums.size(),0);

        for(auto a:nums)
        {
            if(a>=nums.size())
                return false;
            if(a<nums.size()-1 && count[a]>0)
                return false;
            if(a==nums.size()-1 && count[a]>1)
                return false;
            
            count[a]++;
        }
        return true;
    }
};