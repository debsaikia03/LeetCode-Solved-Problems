class Solution {
public:

    void getAllSubsets(vector<int> &nums, int idx, vector<int> &subset, vector<vector<int>> &ans){

        ans.push_back(subset);

        for(int i = idx; i < nums.size(); i++){

            if(i > idx && nums[i] == nums[i-1]) continue;

            subset.push_back(nums[i]);

            getAllSubsets(nums, i+1, subset, ans);

            subset.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        
        vector<int> subset;

        vector<vector<int>> ans;

        getAllSubsets(nums, 0, subset, ans);

        return ans;
    }
};