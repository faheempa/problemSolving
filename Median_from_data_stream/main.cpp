// Question
// https://leetcode.com/problems/find-median-from-data-stream/description/


#include <bits/stdc++.h>
using namespace std;

class MedianFinder
{
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> big;
    int size;

public:
    MedianFinder()
    {
        size = 0;
    }

    void addNum(int num)
    {
        int a;
        small.push(num);
        if (not big.empty() and small.top() > big.top())
        {
            a = small.top();
            small.pop();
            big.push(a);
        }
        if (abs(int(small.size()) - int(big.size())) > 1)
        {
            if (int(small.size()) > int(big.size()))
                a = small.top(), small.pop(), big.push(a);
            else
                a = big.top(), big.pop(), small.push(a);
        }
        size++;
    }

    double findMedian()
    {
        if (size == 0)
            return 0.0;
        if (size % 2 == 0)
            return double(small.top() + big.top()) / 2;
        if (int(big.size()) > int(small.size()))
            return big.top();
        else
            return small.top();
    }
};

int main()
{
    MedianFinder m = MedianFinder();
    m.addNum(4);
    m.addNum(2);
    m.addNum(3);
    m.addNum(1);
    m.addNum(5);

    cout << m.findMedian() << endl;

    m.addNum(6);
    cout << m.findMedian() << endl;
}
