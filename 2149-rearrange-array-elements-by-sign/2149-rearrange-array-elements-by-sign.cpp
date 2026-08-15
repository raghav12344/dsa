class Solution {
public:
    // vector<int> rearrangeArray(vector<int>& nums) {
    //     vector<int> pos{};
    //     vector<int> neg{};
    //     for(int i=0;i<nums.size();i++)
    //     {
    //         if(nums[i]<0)
    //             neg.push_back(nums[i]);
    //         if(nums[i]>=0)
    //             pos.push_back(nums[i]);
    //     }
    //     int i=0;
    //     while(i<nums.size()/2)
    //     {
    //         nums[i*2]=pos[i];
    //         nums[i*2+1]=neg[i];
    //         i++;
    //     }
    //     return nums;
    // }


    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);

        int posIndex = 0; // even indices
        int negIndex = 1; // odd indices

        for (int num : nums) {
            if (num >= 0) {
                result[posIndex] = num;
                posIndex += 2;
            } else {
                result[negIndex] = num;
                negIndex += 2;
            }
        }

        return result;
    }
};