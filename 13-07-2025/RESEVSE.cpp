#include <iostream>
#include <climits>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            
            // Check for overflow before it happens
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
            
            rev = rev * 10 + pop;
        }
        return rev;
    }
};
int main() {
    Solution solution;
    int x = 123;
    int result = solution.reverse(x);
    cout << "Reversed number: " << result << endl;
    int a = -123;
    result = solution.reverse(a);
    cout << "Reversed number: " << result << endl;
    return 0;   
}