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

    TreeNode* deleteNode(TreeNode* root, int key) {

        if(!root) return nullptr;
        
        if(key < root->val) root->left = deleteNode(root->left, key);

        else if(key > root->val) root->right = deleteNode(root->right, key);

        else {

            //node with 0 or 1 child
            if(!root->left) return root->right;
            if(!root->right) return root->left;

            //node with 2 childrem
            //inorder successor
            TreeNode* minNode = root->right;
            while(minNode->left) minNode = minNode->left;

            //copy value to the inorder succesor's value
            root->val = minNode->val;

            //delete the inorder successor node by recursively calling the function
            //hits the nullptr in else section
            root->right = deleteNode(root->right, minNode->val);
        }

        return root;
    }
};