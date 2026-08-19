/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int c = 0;
        return kthSmallest(root, k, c);
    }

    int kthSmallest(TreeNode* root, int k, int& c) {
        if(root == nullptr) return -1;
        int val = kthSmallest(root -> left, k, c);
        if(val != -1) return val;
        ++c;
        if(k == c) return root -> val;
        return kthSmallest(root -> right, k, c);
    }

};
