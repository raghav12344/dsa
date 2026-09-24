class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        set<int> st;
        for(auto v:nums1)
            st.insert(v);

        sort(nums2.begin(),nums2.end());

        for(int i=0;i<nums2.size();i++)
        {
            if(st.find(nums2[i])!=st.end())
                return nums2[i];
        }
        return -1;
    }
};