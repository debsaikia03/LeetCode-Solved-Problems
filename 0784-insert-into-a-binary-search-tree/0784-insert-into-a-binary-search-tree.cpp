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
    
    void insert(TreeNode*& node,int val){

        if(node == nullptr){

            node = new TreeNode(val);
            return;
        } 

        if(val <= node->val) insert(node->left, val);

        if(val > node->val) insert(node->right, val);
    }
    

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        
        insert(root, val);

        return root;
    }
};