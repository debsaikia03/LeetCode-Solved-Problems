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

    int max_d = 0;

    int length(TreeNode* node){

        if(node == nullptr) return 0;

        int l = length(node->left);
        int r = length(node->right);
        
        max_d = max(max_d, l+r);

        return max(l,r)+1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        
        length(root);

        return max_d;
    }
};