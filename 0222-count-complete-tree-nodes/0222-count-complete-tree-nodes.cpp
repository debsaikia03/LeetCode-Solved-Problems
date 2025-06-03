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

    int count(TreeNode* node){

        if(node == nullptr) return 0;

        int l = count(node->left);
        int r = count(node->right);

        return l + r + 1;
    }

    int countNodes(TreeNode* root) {

        return count(root);
        
    }
};