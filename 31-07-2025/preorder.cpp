#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> p;
        Preorder(root,p);
        return p;
    }
    void Preorder(TreeNode* tp,vector<int>&r)
    {
        if(tp!=nullptr)
        {
            Preorder(tp->left,r);
            r.push_back(tp->val);
            Preorder(tp->right,r);
        }
        

    }
};
int main() {
    // Example usage
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution sol;
    vector<int> result = sol.inorderTraversal(root);

    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // Clean up memory
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}