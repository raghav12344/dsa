class Solution {
public:
    bool hascycle(vector<vector<int>> & adj,vector<int> &visited,int i)
    {
        if(visited[i]==1)
            return true;
        if(visited[i]==2)
            return false;
        visited[i]=1;
        for(auto v:adj[i])
        {
            if(hascycle(adj,visited,v))
                return true;
        }
        visited[i]=2;
        return false;
        
    }
    void topo(vector<vector<int>> & adj,vector<int> &visited,int i,stack<int>&st)
    {
        if(visited[i]==1)
            return ;
        visited[i]=1;
        for(auto e:adj[i])
        {
            if(!visited[e])
                topo(adj,visited,e,st);
        }
        st.push(i);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> order;
        for(auto e:prerequisites)
            adj[e[1]].push_back(e[0]);
        
        vector<int> visited(numCourses,0);
        for(int i=0;i<numCourses;i++)
            if(hascycle(adj,visited,i))
                return order;

        for(int i=0;i<numCourses;i++)
            visited[i]=0;
        stack<int> st;
        for(int i=0;i<numCourses;i++)
        {
            if(!visited[i])
                topo(adj,visited,i,st);
        }
        
        while(!st.empty())
        {
            order.push_back(st.top());
            st.pop();
        }
        return order;

    }
};