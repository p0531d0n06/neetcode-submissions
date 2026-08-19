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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> results;
        if(root == nullptr) return results;
        vector<TreeNode*> level;
        vector<int> result;
        int x = 0;
        level.push_back(root);
        int n;
        while(!level.empty()){
            n = level.size();
            for(auto i{0uz}; i < n; ++i){
                result.push_back(level[i] -> val);
                if(level[i] -> left != nullptr) 
                    level.push_back(level[i] -> left);
                if(level[i] -> right != nullptr) 
                    level.push_back(level[i] -> right);
            }

            results.push_back(result);
            for(auto i{0uz}; i < n; ++i){
                level.erase(level.begin());
            }

            result.erase(result.begin(), result.end());
            x++;
        }
        return results;
    }
};
