class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int o=0;
        int t=0;

        for(auto v :nums)
        {
            o^=(v&~t);
            t^=(v&~o);
        }
        return o;
    }
};