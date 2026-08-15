class Solution {
public:
    void dfs(vector<vector<int>>& isConnected,vector<bool> &visited,int src)
    {
        visited[src]=true;
        for(int i=0;i<isConnected[src].size();i++)
        {
            if(isConnected[src][i]==0)
            {
                continue;
            }
            if(visited[i]==false)
                dfs(isConnected,visited,i);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool> visited(isConnected.size(),false);
        int count=0;
        for(int i=0;i<isConnected.size();i++)
        {
            if(!visited[i])
            {
                count++;
                dfs(isConnected,visited,i);
            }
        }
        return count;

    }
};