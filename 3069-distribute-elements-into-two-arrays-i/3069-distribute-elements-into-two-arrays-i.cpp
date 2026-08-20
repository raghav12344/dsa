class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1;
        vector<int> arr2;

        if(nums.size()<=1)
            return nums;

        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        for(int k=2;k<nums.size();k++)
        {
            if(arr1[arr1.size()-1]>arr2[arr2.size()-1])
            {
                arr1.push_back(nums[k]);
            }
            else
                arr2.push_back(nums[k]);
        }
        arr1.insert(arr1.end(),arr2.begin(),arr2.end());
        return arr1;
    }
};