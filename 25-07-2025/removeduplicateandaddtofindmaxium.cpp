#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <climits>
using namespace std;
class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> seen;
        int sum = 0;
        bool hasNonNegative = false;
        int maxNegative = INT_MIN;

        for (int num : nums) {
            if (num >= 0) {
                hasNonNegative = true;
                if (seen.find(num) == seen.end()) {
                    sum += num;
                    seen.insert(num);
                }
            } else {
                maxNegative = max(maxNegative, num);
            }
        }

        if (hasNonNegative) {
            return sum;
        } else {
            return maxNegative;
        }
    }
};
int main() {
    Solution solution;
    vector<int> nums = {1, 2, -3, 4, 5, 1, 2}; // Example input
    int result = solution.maxSum(nums);
    cout << "Maximum sum of unique non-negative integers: " << result << endl;
    return 0;
}