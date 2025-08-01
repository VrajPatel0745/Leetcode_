#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for (int i = 0; i < numRows; i++) {
            vector<int> row(i + 1, 1);  // Initialize row with 1s
            for (int j = 1; j < i; j++) {
                row[j] = result[i - 1][j - 1] + result[i - 1][j];
            }
            result.push_back(row);
        }
        return result;
    }
};
int main() {
    Solution sol;
    int numRows;
    cout << "Enter the number of rows for Pascal's Triangle: ";
    cin >> numRows;
    
    vector<vector<int>> triangle = sol.generate(numRows);
    
    cout << "Pascal's Triangle:" << endl;
    for (const auto& row : triangle) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    return 0;
}