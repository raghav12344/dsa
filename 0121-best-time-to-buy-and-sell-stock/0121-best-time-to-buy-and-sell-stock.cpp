class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn=prices[0];
        int res=0;
        for(int i=0;i<prices.size();i++)
        {
            mn=min(prices[i],mn);
            res=max(res,prices[i]-mn);
        }
        return res;
    }
};