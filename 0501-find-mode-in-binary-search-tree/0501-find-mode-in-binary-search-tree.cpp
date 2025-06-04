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

    void inorder(TreeNode* node, vector<int>& arr){

        if(node == nullptr) return;

        inorder(node->left, arr);
        arr.push_back(node->val);
        inorder(node->right, arr);
    }

    vector<int> findMode(TreeNode* root) {

        vector<int> arr;

        inorder(root, arr);

        unordered_map<int,int> freq;
        int max_c = 0;
        vector<int> result;

        for(int i : arr){

            freq[i]++;

            if(freq[i] > max_c) max_c = freq[i];
        }

        for(auto& i : freq){

            if(i.second == max_c) result.push_back(i.first);
        }

        return result;      
    }
};