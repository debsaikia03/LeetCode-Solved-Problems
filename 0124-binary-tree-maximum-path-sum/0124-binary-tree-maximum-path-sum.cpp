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

    int max_s = INT_MIN;

    int path(TreeNode* node){

        if(node == nullptr) return 0;

        int l = max(0,path(node->left));
        int r = max(0,path(node->right));

        max_s = max(max_s, l+r+node->val); 

        return node->val + max(l,r);

    }
    int maxPathSum(TreeNode* root) {
        
        path(root);
        return max_s;
    }
};