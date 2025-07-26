#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        bool inWord = false;

        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] != ' ') {
                length++;
                inWord = true;
            } else if (inWord) {
                break;
            }
        }

        return length;
    }
};
int main() {
    Solution solution;
    string s = "Hello World";
    int result = solution.lengthOfLastWord(s);
    cout << "Length of the last word: " << result << endl;
    return 0;
}