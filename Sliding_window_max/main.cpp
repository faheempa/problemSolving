// Question
// https://leetcode.com/problems/sliding-window-maximum/description/

#include <bits/stdc++.h>
using namespace std;
template <class T>
void print(T elems)
{
    for (auto elem : elems)
        cout << elem << " ";
}
void read_int_vector(vector<int> &vec)
{
    string input;
    getline(cin, input);
    if (input.length() == 0)
        return read_int_vector(vec);
    istringstream is(input);
    vec = vector<int>((istream_iterator<int>(is)), istream_iterator<int>());
}

template <class T>
class monotonic_Queue
{
private:
    deque<T> q;

public:
    void push(T x)
    {
        while (!q.empty() && q.back() < x)
            q.pop_back();
        q.push_back(x);
    }
    void pop()
    {
        q.pop_front();
    }
    T max()
    {
        return q.front();
    }
    bool empty()
    {
        return q.empty();
    }
};

vector<int> solve(vector<int> &nums, int k)
{
    if (nums.size() < k)
        return {};
    monotonic_Queue<int> mq;
    vector<int> result;
    int i, j = 0;
    for (i = 0; i < k; i++)
        mq.push(nums.at(i));

    while (i < nums.size())
    {
        result.push_back(mq.max());
        if (nums.at(j) == mq.max())
            mq.pop();
        mq.push(nums.at(i));
        i++, j++;
    }
    result.push_back(mq.max());
    return result;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        vector<int> nums;
        read_int_vector(nums);
        int k;
        cin >> k;
        cout << "Case #" << i << ": ";
        print(solve(nums, k));
        cout << endl;
    }
}
