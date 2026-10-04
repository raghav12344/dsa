class Solution {
public:
    int ans=INT_MAX;
    bool isSafe(vector<vector<int>> &heights,int i,int j)
    {
        return i>=0 && j>=0 && i<heights.size() && j<heights[0].size();
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        vector<vector<int>> dist(heights.size(),vector<int>(heights[0].size(),INT_MAX));
       
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,   greater<pair<int,pair<int,int>>>> pq;
        dist[0][0]=0;
        pq.push({0,{0,0}});
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        while(!pq.empty())
        {
            auto[effort,pos]=pq.top();
            pq.pop();
            int i=pos.first;
            int j=pos.second;
            if(effort>dist[i][j])
                continue;
            if(i==heights.size()-1 && j==heights[0].size()-1)
                return effort;
            for(int k=0;k<4;k++)
            {
                int ni=i+dx[k];
                int nj=j+dy[k];
                if(!isSafe(heights,ni,nj))
                    continue;
                int edge=abs(heights[ni][nj]-heights[i][j]);
                int neweffort=max(effort,edge);
                if(neweffort<dist[ni][nj])
                {
                    dist[ni][nj]=neweffort;
                    pq.push({neweffort,{ni,nj}});
                }
            }
        }
        return 0;
    }
};