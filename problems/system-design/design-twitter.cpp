// Design Twitter

// Design a simplified version of Twitter where users can post tweets, follow/unfollow another user, and is able to see the 10 most recent tweets in the user's news feed.

// Implement the Twitter class:

// Twitter() Initializes your twitter object.
// void postTweet(int userId, int tweetId) Composes a new tweet with ID tweetId by the user userId. Each call to this function will be made with a unique tweetId.
// List<Integer> getNewsFeed(int userId) Retrieves the 10 most recent tweet IDs in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user themself. Tweets must be ordered from most recent to least recent.
// void follow(int followerId, int followeeId) The user with ID followerId started following the user with ID followeeId.
// void unfollow(int followerId, int followeeId) The user with ID followerId started unfollowing the user with ID followeeId.


#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;


class Twitter {
private:
    int timestamp;
    unordered_map<int, vector<pair<int,int>>> userTweets; // userId → [(time, tweetId)]
    unordered_map<int, unordered_set<int>> userFollow;    // userId → set of followees

public:
    Twitter() {
        timestamp = 0;
    }

    void postTweet(int userId, int tweetId) {
        userTweets[userId].push_back({timestamp++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        // Max heap: (timestamp, tweetId)
        priority_queue<pair<int,int>> maxHeap;

        // Add user's own tweets
        userFollow[userId].insert(userId);

        // Push all tweets from user + followees into heap
        for (int followee : userFollow[userId]) {
            for (auto& [time, tid] : userTweets[followee]) {
                maxHeap.push({time, tid});
            }
        }

        // Pick top 10
        vector<int> feed;
        while (!maxHeap.empty() && feed.size() < 10) {
            feed.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return feed;
    }

    void follow(int followerId, int followeeId) {
        userFollow[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        userFollow[followerId].erase(followeeId);
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

int main() {
    Twitter* obj = new Twitter();
    obj->postTweet(1, 5);
    vector<int> feed = obj->getNewsFeed(1);
    for (int tid : feed) cout << tid << " "; // 5
    cout << endl;
    obj->follow(1, 2);
    obj->postTweet(2, 6);
    feed = obj->getNewsFeed(1);
    for (int tid : feed) cout << tid << " "; // 6 5
    cout << endl;
    obj->unfollow(1, 2);
    feed = obj->getNewsFeed(1);
    for (int tid : feed) cout << tid << " "; // 5
    cout << endl;
    return 0;
}

// Time Complexity: O(N log N) for getNewsFeed where N is total tweets from user + followees.
// Space Complexity: O(N) for storing tweets and follow relationships.