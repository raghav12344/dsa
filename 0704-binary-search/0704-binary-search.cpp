class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lft=0,rgt=nums.size()-1;
        int idx=-1;
        while(lft<=rgt)
        {
            int mid=(lft+rgt)/2;
            if(nums[mid]==target)
            {
                idx=mid;
                break;
            }
            else if(nums[mid]>target)
                rgt=mid-1;
            else if(nums[mid]<target)
                lft=mid+1;
        }
        return idx;
    }
};