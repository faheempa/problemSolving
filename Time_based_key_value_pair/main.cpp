// Question
// https://leetcode.com/problems/time-based-key-value-store/

#include <bits/stdc++.h>
using namespace std;

class TimeMap
{
    unordered_map<string, vector<pair<string, int>>> mp;

public:
    TimeMap()
    {
    }

    void set(string key, string value, int timestamp)
    {
        mp[key].push_back({value, timestamp});
    }

    string get(string key, int timestamp)
    {
        if (mp.find(key) == mp.end())
            return "";

        auto &vec = mp[key];
        int l = 0;
        int r = vec.size() - 1;
        string ans;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (vec.at(mid).second <= timestamp)
            {
                ans = vec.at(mid).first;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return ans;
    }
};

int main()
{
    TimeMap m;
    m.set("abc", "one", 1);
    m.set("abc", "two", 3);
    m.set("abc", "three", 5);
    m.set("xyz", "zero", 4);
    m.set("xyz", "ten", 10);

    cout << m.get("abc", 1) << endl; // one
    cout << m.get("abc", 2) << endl; // one
    cout << m.get("abc", 4) << endl; // two
    cout << m.get("abc", 5) << endl; // three
    cout << m.get("xyz", 1) << endl; // ""
    cout << m.get("xyz", 10) << endl; // ten
    cout << m.get("xyz", 20) << endl; // ten
}
