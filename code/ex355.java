class Twitter {
    public int time;
    public Map<Integer, List<Integer>> tweets;
    public Map<Integer, Integer> id2time;
    public Map<Integer, Set<Integer>> follow;

    /** Initialize your data structure here. */
    public Twitter() {
        time = 0;
        tweets = new HashMap<Integer, List<Integer>>();
        id2time = new HashMap<Integer, Integer>();
        follow = new HashMap<Integer, Set<Integer>>();
    }
    
    /** Compose a new tweet. */
    public void postTweet(int userId, int tweetId) {
        id2time.put(tweetId, time++);
        
        List<Integer> list = tweets.getOrDefault(userId, new ArrayList<Integer>());
        list.add(tweetId);
        tweets.put(userId, list);
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    public List<Integer> getNewsFeed(int userId) {
        List<Integer> feed = new ArrayList<>();
        // Add his personal tweets to the feed
        if (tweets.containsKey(userId)) {
            for (int tweet : tweets.get(userId))
                feed.add(tweet);
        }
        
        // Add the tweets from people he follows
        if (follow.containsKey(userId)) {
            System.out.println(follow.get(userId));
            for (int f : follow.get(userId)) {
                if (tweets.containsKey(f)) {
                    for (int tweet : tweets.get(f)) {
                        feed.add(tweet);
                    }
                } 
            }
        }
        
        Collections.sort(feed, new Comparator<Integer>() {
            public int compare(Integer a, Integer b) {
                return id2time.get(b) - id2time.get(a);
            }
        });
        
        return feed.subList(0, Math.min(feed.size(), 10));
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    public void follow(int followerId, int followeeId) {
        if (followerId == followeeId)    return;
        Set<Integer> followees = follow.getOrDefault(followerId, new HashSet<Integer>());
        followees.add(followeeId);
        follow.put(followerId, followees);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    public void unfollow(int followerId, int followeeId) {
        if (!follow.containsKey(followerId) || followerId == followeeId)    return;
        Set<Integer> followees = follow.get(followerId);
        if (followees.contains(followeeId)) {
            followees.remove(followeeId);
        }
        follow.put(followerId, followees);
    }
}

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * List<Integer> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */