// Question
// https://leetcode.com/problems/kth-largest-element-in-a-stream/description/

#include <bits/stdc++.h>
using namespace std;

class KthLargest
{
    priority_queue<int, vector<int>, greater<int>> q;
    int k;

public:
    KthLargest(int k, vector<int> &nums)
    {
        for (int i = 0; i < k; i++)
            q.push(INT_MIN);

        for (int i = 0; i < nums.size(); i++)
            q.push(nums.at(i));

        while (q.size() > k)
            q.pop();
    }

    int add(int val)
    {
        q.push(val);
        q.pop();
        return q.top();
    }
};

int main()
{
    vector<int> nums{4, 5, 8, 2};
    int k = 3;

    KthLargest obj{k, nums};
    cout << obj.add(3) << endl;
    cout << obj.add(5) << endl;
    cout << obj.add(10) << endl;
    cout << obj.add(9) << endl;
    cout << obj.add(4) << endl;
}
