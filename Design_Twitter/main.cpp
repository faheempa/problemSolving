// Question
// https://leetcode.com/problems/design-twitter/

#include <bits/stdc++.h>
using namespace std;
template <class T>
void print(T elems)
{
    for (auto elem : elems)
        cout << elem << " ";
}

class Twitter
{
    unordered_map<int, unordered_set<int>> follows;
    vector<pair<int, int>> twts;

public:
    Twitter()
    {
    }

    void postTweet(int userId, int tweetId)
    {
        twts.push_back({userId, tweetId});
    }

    vector<int> getNewsFeed(int userId)
    {
        vector<int> feed;
        int count = 0;
        for (int i = twts.size() - 1; i >= 0; i--)
        {
            if (count == 10)
                break;

            int id = twts.at(i).first;
            if (id == userId or follows[userId].find(id) != follows[userId].end())
            {
                feed.push_back(twts.at(i).second);
                count++;
            }
        }
        return feed;
    }

    void follow(int followerId, int followeeId)
    {
        if (followerId == followeeId)
            return;
            
        follows[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        follows[followerId].erase(followeeId);
    }
};

int main()
{
    Twitter tw = Twitter();
    tw.follow(2, 3);
    tw.follow(2, 5);
    tw.follow(2, 1);

    tw.unfollow(2, 3);

    tw.postTweet(1, 10);
    tw.postTweet(2, 20);
    tw.postTweet(3, 30);
    tw.postTweet(5, 50);

    print(tw.getNewsFeed(2)); // 20, 50, 10
}
