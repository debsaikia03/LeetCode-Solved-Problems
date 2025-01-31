class Solution {
public:

    void getAllSubsets(vector<int> &nums, int idx, vector<int> &subset, vector<vector<int>> &ans){

        ans.push_back(subset);

        for(int i = idx; i < nums.size(); i++){

            subset.push_back(nums[i]);

            getAllSubsets(nums, i+1, subset, ans);

            subset.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        

        vector<int> subset;

        vector<vector<int>> ans;

        getAllSubsets(nums, 0, subset, ans);

        return ans;
    }
};