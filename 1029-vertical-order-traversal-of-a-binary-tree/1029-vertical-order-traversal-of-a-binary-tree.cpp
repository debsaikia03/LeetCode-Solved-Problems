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
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        map<int, map<int, multiset<int>>> nodes; //verticals //levels //multiple nodes of every level
        queue<pair<TreeNode*, pair<int,int>>> todo; //node, vertical, level
        todo.push({root,{0,0}});//initially push the root with its vertical & level

        while(!todo.empty()){

            auto p = todo.front();
            todo.pop();

            TreeNode* node = p.first; //node

            int x = p.second.first; //vertical order
            int y = p.second.second; //level order

            nodes[x][y].insert(node->val); //insert the value of the node in the corresponding vertical and level

            if(node->left){
                todo.push({node->left,{x - 1, y + 1}}); // push left child with updated vertical and level
            }

            if(node->right){
                todo.push({node->right,{x + 1, y + 1}}); // push right child with updated vertical and level
            }
        }

        vector<vector<int>> ans;

        for(auto p : nodes){

            vector<int> col; //to store the values of each vertical
            //p.first -> vertical order

            for(auto q : p.second){//p.second-> map<int, multiset>
                col.insert(col.end(), q.second.begin(), q.second.end()); //q.second -> multiset<int>
                //insert all values of the current level into the column vector
                //push_back is used insert single element at the back
                //col.insert and col.end() is used to insert range of elements at the back
            }
            ans.push_back(col);
        }

        return ans;
    }
};