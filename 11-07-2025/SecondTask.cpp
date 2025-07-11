#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1; 

        while (low <= high) {
            int mid = low + (high - low) / 2; 
            int n = nums[mid];

            if (n == target) {
                return mid;
            } else if (n < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return -1;
    }
};
int main() {
    Solution solution;
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;
    int result = solution.search(nums, target);
    cout << "Index of target " << target << ": " << result << endl; // Output: 4

    target = 2;
    result = solution.search(nums, target);
    cout << "Index of target " << target << ": " << result << endl; // Output: -1

    return 0;
}
