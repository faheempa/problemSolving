// question
// https://leetcode.com/problems/text-justification/description/

#include <bits/stdc++.h>
using namespace std;
void read_string_vector(vector<string> &vec)
{
    string input;
    string word = "";
    getline(cin, input);
    if (input.length() == 0)
        return read_string_vector(vec);
    
}
vector<string> solve(vector<string> &words, int maxWidth)
{
    vector<string> result;
    int i = 0;

    while (i < words.size())
    {
        // get the line width, without including spaces
        int lineLength = words[i].length();
        int j = i + 1;
        while (j < words.size() && lineLength + words[j].length() + (j - i) <= maxWidth)
        {
            lineLength += words[j].length();
            ++j;
        }

        // calculate spaces
        int spacePosNo = j - i - 1;
        int totalSpaces = maxWidth - lineLength;
        int AvgSpaces{1};
        int ExtraSpace{0};
        if (spacePosNo > 0)
        {
            AvgSpaces = totalSpaces / spacePosNo;
            ExtraSpace = totalSpaces % spacePosNo;
        }

        // Construct the line
        string line = words[i];
        for (int k = i + 1; k < j; ++k)
        {
            int spaceNeed;
            if (j == words.size())
                spaceNeed = 1;
            else
            {
                spaceNeed = AvgSpaces;
                if (ExtraSpace)
                {
                    spaceNeed++;
                    ExtraSpace--;
                }
            }
            line += string(spaceNeed, ' ') + words[k];
        }

        // Pad extra spaces for the last line
        line += string(maxWidth - line.length(), ' ');
        result.push_back(line);
        i = j;
    }
    return result;
}

int main()
{

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        vector<string> words;
        read_string_vector(words);
        int maxWidth;
        cin >> maxWidth;
        cout << "Case #" << i << ": " << endl;
        for (auto &line : solve(words, maxWidth))
        {
            cout << "|" << line << "|" << endl;
        }
        cout << endl;
    }
}