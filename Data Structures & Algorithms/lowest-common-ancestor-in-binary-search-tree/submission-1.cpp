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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* p_tracker = root;
        TreeNode* q_tracker = root;
        TreeNode* prev;
        while(p_tracker -> val == q_tracker -> val){
            prev = p_tracker;
            if(p -> val < p_tracker -> val)
                p_tracker = p_tracker -> left;
            else if(p -> val > p_tracker -> val) 
                p_tracker = p_tracker -> right;
            else 
                return p_tracker;

            if(q -> val < q_tracker -> val)
                q_tracker = q_tracker -> left;
            else if(q -> val > q_tracker -> val)
                q_tracker = q_tracker -> right;
            else 
                return q_tracker;

        }

        return prev;
    }
};
