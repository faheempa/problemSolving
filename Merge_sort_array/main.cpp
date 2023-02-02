// Question
// https://leetcode.com/problems/merge-sorted-array/description/

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

void solve(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i = 0, j = 0;
    vector<int> x;
    while (i < m && j < n)
        (nums1.at(i) < nums2.at(j)) ? x.push_back(nums1.at(i++)) : x.push_back(nums2.at(j++));
    while (i < m)
        x.push_back(nums1.at(i++));
    while (j < n)
        x.push_back(nums2.at(j++));
    nums1.clear();
    for (int &var : x)
        nums1.push_back(var);
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        vector<int> num1, num2;
        int n, m;
        read_int_vector(num1);
        cin >> m;
        read_int_vector(num2);
        cin >> n;
        cout << "Case #" << i << ": ";
        solve(num1, m, num2, n);
        print(num1);
        cout << endl;
    }
}
