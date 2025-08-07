#include <iostream>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int countNodes(TreeNode *root)
    {
        int count = 0;
        countNodesHelper(root, count);
        return count;
    }

    void countNodesHelper(TreeNode *node, int &count)
    {
        if (node == nullptr)
            return;

        count++;
        countNodesHelper(node->left, count);
        countNodesHelper(node->right, count);
    }
};
int main()
{
    Solution solution;
    TreeNode *root = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    cout << solution.countNodes(root) << endl; // Output: 3
    return 0;
}