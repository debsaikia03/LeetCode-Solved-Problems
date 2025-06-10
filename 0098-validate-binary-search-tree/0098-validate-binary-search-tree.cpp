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

    bool helper(TreeNode* node, long long min, long long max){
        
        if(!node) return true;

        if(node->val <= min || node->val >= max) return false; //out of range

        return helper(node->left, min, node->val) && helper(node->right, node->val, max);
    }
    bool isValidBST(TreeNode* root) {

        return helper(root, LLONG_MIN, LLONG_MAX);
    }
};