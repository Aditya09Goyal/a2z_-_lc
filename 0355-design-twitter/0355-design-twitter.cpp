class Twitter {
private: 
    int time ; 
    vector<vector<int>>tweets ;  // [ time , userId , tweetId ]
    unordered_map<int,unordered_set<int>>following ; // userId -> following list
public:
    Twitter() {
        time = 0 ; 
    }
    
    void postTweet(int userId, int tweetId) {
        tweets.push_back({ time , userId, tweetId }) ; 
        time++; 
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int>feed ; 
        for(int i=tweets.size()-1;i>=0;i--)
        {
            if(feed.size()==10) break ; 
            int tweet_poster = tweets[i][1] ; 
            int tweet = tweets[i][2] ; 
            if(tweet_poster==userId or following[userId].count(tweet_poster) )
            {
                feed.push_back(tweet); 
            }
        }
        return feed ; 
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId) ;
    }
    
    void unfollow(int followerId, int followeeId) {
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