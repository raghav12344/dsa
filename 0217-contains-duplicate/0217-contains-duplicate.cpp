class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        for(auto v:nums)
            st.insert(v);
        
        return st.size()<nums.size();
    }
};