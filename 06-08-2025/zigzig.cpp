#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1 || s.size() <= numRows) return s;

        vector<string> R(numRows);
        int row = 0;
        bool isDown = true;

        for(char c : s) {
            R[row] += c;

            if(row == 0)
                isDown = true;
            else if(row == numRows - 1)
                isDown = false;

            row += isDown ? 1 : -1;
        }

        string result;
        for(const string& str : R)
            result += str;

        return result;
    }
};
int main() {
    Solution solution;
    string s = "PAYPALISHIRING";
    int numRows = 3;
    cout << solution.convert(s, numRows) << endl; // Output: "PAHNAPLSIIGYIR"
    return 0;
}