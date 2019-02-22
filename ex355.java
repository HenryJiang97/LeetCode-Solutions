import java.util.List;
import java.util.ArrayList;
import java.util.HashMap;


class Twitter {
    // Create a data structure: tweet
    class Tweet {
        int userId;
        int tweetId;
        public Tweet(int user, int tweet) {userId = user;    tweetId = tweet;}
    }
    
    // Global variable
    public List<Tweet> tweet;
    public HashMap<Integer, List<Integer>> follows;
    

    /** Initialize your data structure here. */
    public Twitter() {
        tweet = new ArrayList<Tweet>();
        follows = new HashMap<Integer, List<Integer>>();
    }
    

    /** Compose a new tweet. */
    public void postTweet(int userId, int tweetId) {
        // Add user to follows map
        if (!follows.containsKey(userId))    follows.put(userId, new ArrayList<Integer>());
        
        // Add tweet to tweet list
        tweet.add(new Tweet(userId, tweetId));
    }
    

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    public List<Integer> getNewsFeed(int userId) {
        // If userid not in follows map
        if (!follows.containsKey(userId))    return new ArrayList<>();

        List<Integer> feed = new ArrayList<>();
        List<Integer> feedUser = follows.get(userId);
        feedUser.add(userId);    // Add the user itself to the list

        int counter = 0;
        for (int i = tweet.size() - 1; i >= 0; i--) {
            if (feedUser.contains(tweet.get(i).userId)) {
                if (counter >= 10)    break;
                feed.add(tweet.get(i).tweetId);
                counter++;
            }
        }

        return feed;
    }
    

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    public void follow(int followerId, int followeeId) {
        // Add user to follows map if not exist
        if (!follows.containsKey(followerId))    follows.put(followerId, new ArrayList<Integer>());
        
        List<Integer> f = follows.get(followerId);
        f.add(followeeId);
        follows.put(followerId, f);
    }
    

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    public void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            if(follows.containsKey(followerId)) {
                List<Integer> f = follows.get(followerId);
                
                if (f.contains(followeeId)) {
                    f.remove(f.indexOf(followeeId));
                    follows.put(followerId, f);
                }
            }        
        }
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