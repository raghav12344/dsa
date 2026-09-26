class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        for(auto v:nums)
            mp[v]++;
        
        priority_queue<pair<int,int>> pq;

        for(auto pr:mp)
            pq.push({pr.second,pr.first});
        vector<int> ans;
        while(k>0)
        {
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return ans;
        
    }
};