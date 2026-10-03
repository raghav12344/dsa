class Twitter {
public:
    vector<pair<int,int>> tweets[501];
    unordered_set<int> following[501];
    int time=0;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++,tweetId});
    }
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int n=tweets[userId].size();
        for(int i=n-1;i>=max(0,n-10);i--)
        {
            pq.push(tweets[userId][i]);
            if(pq.size()>10)
                pq.pop();
        }

        for(int f:following[userId])
        {
            n=tweets[f].size();
            for(int i=n-1;i>=max(0,n-10);i--)
            {
                pq.push(tweets[f][i]);
                if(pq.size()>10)
                    pq.pop();
            }
        }
        vector<int> feed;
        while(!pq.empty())
        {
            feed.push_back(pq.top().second);
            pq.pop();
        }
        reverse(feed.begin(),feed.end());
        return feed;
    }
    
    
    void follow(int followerId, int followeeId) {
        if(followerId!=followeeId)
            following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId!=followeeId)
            following[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */