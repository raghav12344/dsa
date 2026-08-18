class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        map<int,int> mp;
        for (int i = 0; i <= nums.size() - k; i++) {
            set<int> st;

            for (int j = i; j < i + k; j++) {
                st.insert(nums[j]);
            }

            for (int x : st) {
                mp[x]++;
            }
        }
        int larg=-1;
        for(auto pr:mp)
        {
            if(pr.second==1)
                larg=max(larg,pr.first);
        }
        return larg;
    }
};