class Solution {
public:
    bool dfs(vector<vector<int>>& graph,vector<int> &visited,int i,int color)
    {
        
        visited[i]=color;
        for(auto v:graph[i])
        {
            if(visited[v]==-1)
            {
                if(!dfs(graph,visited,v,1-color))
                    return false;
            }
            else 
            {
                if(visited[v]==color)
                    return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> visited(graph.size(),-1);

        for(int i=0;i<graph.size();i++)
            if(visited[i]==-1)
                if(!dfs(graph,visited,i,0))
                    return false;
        return true;
    }
};