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

    void findAllPaths(TreeNode* node, string path, vector<string>& ans){

        if(!node) return;

        if(node->left == nullptr && node->right == nullptr){
            
            ans.push_back(path);
            return;
        }

        if(node->left) findAllPaths(node->left, path+"->"+to_string(node->left->val), ans);

        if(node->right) findAllPaths(node->right, path+"->"+to_string(node->right->val), ans);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        
        vector<string> ans;

        string path = to_string(root->val);

        findAllPaths(root, path, ans);

        return ans;
    }
};