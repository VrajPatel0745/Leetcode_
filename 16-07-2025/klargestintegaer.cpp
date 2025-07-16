#include <iostream>
#include <vector>
#include <queue>    
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
                priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        return minHeap.top();
}
};

int main() {
    Solution s;
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2; // Find the 2nd largest element
    cout << "The " << k << "th largest element is: " << s.findKthLargest(nums, k) << endl;
    return 0;
}