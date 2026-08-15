class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mxending=nums[0];
        int res=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            mxending=max(nums[i],nums[i]+mxending);

            res=max(res,mxending);
        }
        return res;
    }
};