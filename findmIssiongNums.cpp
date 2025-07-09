// Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
       int n = nums.size();
        int expected_sum = n * (n + 1) / 2;
        int actual_sum = 0;
        for(int num : nums) {
            actual_sum += num;
        }
        return expected_sum - actual_sum;
    }
    
};
int main() {
    Solution solution;
    vector<int> nums = {3, 0, 1};
    cout << "Missing number: " << solution.missingNumber(nums) << endl; // Output: 2
    vector<int> nums1 = {3, 0, 1,5,4,6,8,9,7};
     cout << "Missing number: " << solution.missingNumber(nums1) << endl; // Output: 2
      vector<int> nums2 = {2, 0, 1,5,4,6,8,9,7};
     cout << "Missing number: " << solution.missingNumber(nums2) << endl; // Output: 3
    return 0;
}