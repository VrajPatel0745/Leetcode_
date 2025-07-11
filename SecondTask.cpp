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
