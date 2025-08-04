#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int high=nums.size()-1,low=0;

        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            else if(nums[mid]<target)
            {
                low=mid+1;
            }
            else if(nums[mid]>target)
            {
                high=mid-1;
            }
        }
        return low;
    }
};
int main() {
    Solution solution;
    vector<int> nums = {1, 3, 5, 6};
    int target = 5;
    cout << "Insert position: " << solution.searchInsert(nums, target) << endl; // Output: 2
    return 0;
}