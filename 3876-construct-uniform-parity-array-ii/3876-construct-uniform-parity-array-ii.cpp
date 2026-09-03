class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mn=INT_MAX;
        for(auto x:nums1)
            if(x%2==1)
            mn=min(mn,x);
        for(auto x:nums1)
            if(x%2==0 && mn!=INT_MAX && x<mn)
            return false;

        return true;
    }
};