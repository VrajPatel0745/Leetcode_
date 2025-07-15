#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;
        string result = "";

        while (i >= 0 || j >= 0 || carry) {
            int bit1 = (i >= 0) ? a[i] - '0' : 0;
            int bit2 = (j >= 0) ? b[j] - '0' : 0;

            int sum = bit1 + bit2 + carry;
            result += (sum % 2) + '0';
            carry = sum / 2;

            i--;
            j--;
        }

        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    Solution s;
    string a = "1101";
    string b = "1011";

    string result = s.addBinary(a, b);
    cout << "Sum of binary numbers: " << result << endl;
    return 0;
}
