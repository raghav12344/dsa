class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int l=*min_element(nums.begin(),nums.end());
        int h=*max_element(nums.begin(),nums.end());
        vector<int> res;
        for(int i=l;i<=h;i++)
        {
            if(find(nums.begin(),nums.end(),i)!=nums.end())
                continue;
            else
                res.push_back(i);
        }
        return res;
    }
};