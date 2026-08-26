class Solution {
public:
    bool dfs(vector<vector<int>> &adj,vector<int>&visited,int course)
    {
        if(visited[course]==1)
            return true;
        if(visited[course]==2)
            return false;

        visited[course]=1;
        for(auto vrtx:adj[course])
        {
            if(dfs(adj,visited,vrtx))
                return true;
        }
        visited[course]=2;
        return false;
    }
    bool canFinish(int numsCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numsCourses);

        for(auto edge:prerequisites)
        {
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> visited(numsCourses,0);

        for(int i=0;i<numsCourses;i++)
            if(dfs(adj,visited,i))
                return false;

        return true;
    }
};