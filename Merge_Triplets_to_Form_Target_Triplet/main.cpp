// question
//

#include <bits/stdc++.h>
using namespace std;
template <class T>
void print(T elems)
{
    for (auto elem : elems)
        cout << elem << " ";
}
void read_string_vector(vector<string> &vec)
{
    string input;
    string word = "";
    getline(cin, input);
    if (input.length() == 0)
        return read_string_vector(vec);
    input += " ";
    for (auto var : input)
    {
        if (var == ' ')
        {
            if (word.length() == 0)
                continue;
            vec.push_back(word);
            word = "";
        }
        else
            word += var;
    }
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

bool solve(vector<vector<int>> &triplets, vector<int> &target)
{
    bool target_validator[3]{false};

    for (auto &tri : triplets)
    {
        if (tri[0] > target[0] or tri[1] > target[1] or tri[2] > target[2])
            continue;

        for (int i = 0; i < 3; i++)
            target_validator[i] = target_validator[i] or tri[i] == target[i];
    }

    for (auto &t : target_validator)
        if (t == false)
            return false;
    return true;
}

int main()
{

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int n;
        cin >> n;
        vector<vector<int>> triplets;
        while (n--)
        {
            vector<int> tri;
            read_int_vector(tri);
            triplets.push_back(tri);
        }
        vector<int> target;
        read_int_vector(target);

        cout << "Case #" << i << ": ";
        cout << boolalpha << solve(triplets, target);
        cout << endl;
    }
}