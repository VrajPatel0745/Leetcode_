#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> expected = heights;
        sort(expected.begin(), expected.end());

        int count = 0;
        for (int i = 0; i < heights.size(); i++) {
            if (heights[i] != expected[i]) {
                count++;
            }
        }

        return count;
    }
};
int main() {
    Solution sol;
    vector<int> heights;
    int n, height;

    cout << "Enter the number of students: ";
    cin >> n;
    cout << "Enter the heights of the students: ";
    
    for (int i = 0; i < n; i++) {
        cin >> height;
        heights.push_back(height);
    }

    int result = sol.heightChecker(heights);
    cout << "Number of students not in correct order: " << result << endl;

    return 0;
}