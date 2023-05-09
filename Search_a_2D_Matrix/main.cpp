// Question
// https://leetcode.com/problems/search-a-2d-matrix/

#include <bits/stdc++.h>
using namespace std;

void read_int_vector(vector<int> &vec)
{
    string input;
    getline(cin, input);
    if (input.length() == 0)
        return read_int_vector(vec);
    istringstream is(input);
    vec = vector<int>((istream_iterator<int>(is)), istream_iterator<int>());
}

bool solve(vector<vector<int>> &matrix, int &target)
{
    int c = matrix[0].size();
    int r = matrix.size();
    int right = c * r - 1, left = 0;

    while (right >= left)
    {
        int mid = (right + left) / 2;
        int val = matrix[mid / c][mid % c];

        if (val == target)
            return true;
        else if (val < target)
            left = mid + 1;
        else
            right = mid;
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        vector<vector<int>> matrix;
        int rows;
        cin >> rows;
        for (int i = 0; i < rows; i++)
        {
            vector<int> vec;
            read_int_vector(vec);
            matrix.push_back(vec);
        }
        int target;
        cin >> target;

        cout << "Case #" << i << ": ";
        cout << boolalpha << solve(matrix, target);
        cout << endl;
    }
}
