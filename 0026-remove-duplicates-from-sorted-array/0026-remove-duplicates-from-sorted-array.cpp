class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set <int> st;
        for(auto val:nums)
        {
            st.insert(val);
        }
        nums.clear();
        for(auto val:st)
        {
            nums.push_back(val);
        }
        return st.size();
    }
};