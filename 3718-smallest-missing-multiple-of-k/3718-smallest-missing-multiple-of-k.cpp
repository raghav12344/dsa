class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int high=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%k==0)
            {
                high=max(high,nums[i]/k);
            }
        }
        for(int i=1;i<=high;i++)
        {
            if(find(nums.begin(),nums.end(),i*k)==nums.end())
            {
                return i*k;
            }
        }
        return (high+1)*k;
    }
};