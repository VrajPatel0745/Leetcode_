#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int index1 = first(nums, target);
        int index2 = last(nums, target);
        return {index1, index2};
    }

    int first(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int result = -1;  // ✅ initialize
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                result = mid;
                high = mid - 1;  // search left part
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return result;
    }

    int last(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int result = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                result = mid;
                low = mid + 1;  
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return result;
    }
};
int main() {
    Solution solution;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    vector<int> result = solution.searchRange(nums, target);
    cout << "First and last position: [" << result[0] << ", " << result[1] << "]" << endl; // Output: [3, 4]
    return 0;
}