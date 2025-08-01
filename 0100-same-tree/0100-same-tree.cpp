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
    bool isSameTree(TreeNode* p, TreeNode* q) {

        if(!p && !q) return true; //both is null

        if(!p || !q) return false; //one is null , other is not

        return (p->val == q->val) //value doesn't match
            && isSameTree(p->left, q->left) // check left subtree
            && isSameTree(p->right, q->right); //check right subtree
        
    }
};