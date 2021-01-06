class Twitter {
    unordered_map<int, vector<int>> user2tweets;
    unordered_map<int, int> id2time;
    unordered_map<int, unordered_set<int>> followees;
    int time = 0;
    
public:
    /** Initialize your data structure here. */
    Twitter() {
        
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        user2tweets[userId].push_back(tweetId);
        id2time[tweetId] = time++;
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;    // {time, tweetId}
        
        for (int id : user2tweets[userId]) {    // Add tweets from the user
            pq.push({id2time[id], id});
            if (pq.size() > 10)    pq.pop();
        }
        
        for (int f : followees[userId]) {    // Add tweets from the user's followees;
            for (int id : user2tweets[f]) {
                pq.push({id2time[id], id});
                if (pq.size() > 10)    pq.pop();
            }
        }
        
        vector<int> feed;
        while (!pq.empty()) {
            feed.push_back(pq.top().second);
            pq.pop();
        }
        reverse(feed.begin(), feed.end());
        
        return feed;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId)    return;
        followees[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (followees.count(followerId) == 0 || followees[followerId].count(followeeId) == 0)    return;
        followees[followerId].erase(followeeId);
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