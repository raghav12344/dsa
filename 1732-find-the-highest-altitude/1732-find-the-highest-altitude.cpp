class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int a=0;
        int mx=0;
        for(auto v:gain)
        {
            a+=v;
            mx=max(mx,a);
        }
        return mx;
    }
};