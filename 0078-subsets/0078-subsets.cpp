class Solution {
public:
    vector<vector<int>> res;
    void recur(vector<int> &nums,vector<int> temp,int i)
    {
        if(i==nums.size())
        {
            res.push_back(temp);
            return ;
        }
        
        recur(nums,temp,i+1);
        temp.push_back(nums[i]);
        recur(nums,temp,i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        recur(nums,temp,0);
        return res;
    }
};