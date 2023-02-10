// Question
// https://leetcode.com/problems/intersection-of-two-arrays-ii/description/

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

vector<int> solve(vector<int> &num1, vector<int> &num2)
{
    if (num1.size() > num2.size())
        swap(num1, num2);

    unordered_map<int, int> map;
    for (int &x : num1)
        map[x]++;

    vector<int> vec;
    for (int &x : num2)
        if (map[x])
            vec.push_back(x), map[x]--;

    return vec;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        vector<int> num1, num2;
        read_int_vector(num1);
        read_int_vector(num2);
        cout << "Case #" << i << ": ";
        print(solve(num1, num2));
        cout << endl;
    }
}
