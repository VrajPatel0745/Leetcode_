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
// Example usage
int main()
{
    // Create a simple binary tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution solution;
    int nodeCount = solution.countNodes(root);
    cout << "Number of nodes in the binary tree: " << nodeCount << endl;

    // Clean up memory (not shown here for brevity)
    return 0;
}