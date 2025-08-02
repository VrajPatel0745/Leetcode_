#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return buildBST(nums, 0, nums.size() - 1);
    }

private:
    TreeNode *buildBST(vector<int> &nums, int left, int right)
    {
        if (left > right)
            return nullptr;

        int mid = (left + right) / 2;
        TreeNode *node = new TreeNode(nums[mid]);
        node->left = buildBST(nums, left, mid - 1);
        node->right = buildBST(nums, mid + 1, right);
        return node;
    }
};
int main()
{
    Solution sol;
    vector<int> nums;
    int n, val;

    cout << "Enter the number of elements in the sorted array: ";
    cin >> n;
    cout << "Enter the elements of the sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        nums.push_back(val);
    }

    TreeNode *root = sol.sortedArrayToBST(nums);

    cout << "Binary Search Tree created from the sorted array." << endl;

    // Additional code to print or verify the BST can be added here.

    return 0;
}
