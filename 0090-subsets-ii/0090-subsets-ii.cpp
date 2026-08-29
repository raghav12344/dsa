class Solution {
public:
    void recur(vector<vector<int>> &res,vector<int> &nums,int i,vector<int> temp)
    {
        if(i==nums.size())
        {
            if(find(res.begin(),res.end(),temp)==res.end())
            {
                res.push_back(temp);
            }
            return ;
        }
        recur(res,nums,i+1,temp);
        temp.push_back(nums[i]);
        recur(res,nums,i+1,temp);
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        vector<int> temp;
        recur(res,nums,0,temp);
        return res;
    }
};