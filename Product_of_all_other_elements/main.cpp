// Question
// https://leetcode.com/problems/product-of-array-except-self/description/

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

vector<int> solve(vector<int> &nums)
{
    int len = nums.size();
    if (len <= 1)
        return nums;
    vector<int> ans(len, 1);
    int p1 = 1, p2 = 1;
    for (int i = 0; i < len; i++)
    {
        ans.at(i) *= p1;
        ans.at(len - i - 1) *= p2;
        p1 *= nums.at(i);
        p2 *= nums.at(len - i - 1);
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        vector<int> num;
        read_int_vector(num);

        cout << "Case #" << i << ": ";
        print(solve(num));
        cout << endl;
    }
}
