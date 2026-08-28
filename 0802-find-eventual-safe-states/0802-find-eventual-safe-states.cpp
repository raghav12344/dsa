class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>> revadj(n);

        vector<int> indegree(n,0);

        for(int i=0;i<n;i++)
        {
            for(auto v:graph[i])
            {
                revadj[v].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> q;
        vector<int> ans;

        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        while(!q.empty())
        {
            int cur=q.front();
            q.pop();
            ans.push_back(cur);
            for(int i:revadj[cur])
            {
                indegree[i]--;
                if(indegree[i]==0)
                    q.push(i);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};