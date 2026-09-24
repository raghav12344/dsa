class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        int i=cost.size()-1;
        int sum=0;
        while(i>=0)
        {
            if(i>=0)
                sum+=cost[i];
            i--;
            if(i>=0)
                sum+=cost[i];
            i--;
            i--;
        }
        return sum;
    }
};