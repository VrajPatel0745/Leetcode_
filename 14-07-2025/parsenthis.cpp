#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isValid(string s)
    {
        int n = s.length();
        stack<char> r;
        for (int i = 0; i < n; i++)
        {
            char v = s[i];
            if (v == '(')
            {
                r.push(v);
            }
            if (v == ')')
            {
                if (r.empty() || r.top() != '(')
                {
                    return false;
                }
                r.pop();
            }
            if (v == '[')
            {
                r.push(v);
            }
            if (v == ']')
            {
                if (r.empty() || r.top() != '[')
                {
                    return false;
                }
                r.pop();
            }
            if (v == '{')
            {
                r.push(v);
            }
            if (v == '}')
            {
                if (r.empty() || r.top() != '{')
                {
                    return false;
                }
                r.pop();
            }
        }
        return r.empty();
    }
};
int main()
{
    Solution s;
    string str;
    cout << "Enter the string: ";
    cin >> str;
    if (s.isValid(str))
    {
        cout << "The string is valid" << endl;
    }
    else
    {
        cout << "The string is not valid" << endl;
    }
    return 0;
}