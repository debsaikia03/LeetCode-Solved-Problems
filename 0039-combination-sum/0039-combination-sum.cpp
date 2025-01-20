class Solution {
public:
    void getAllCombin(vector<int>& candidates, int idx, int target, vector<int>& combin, vector<vector<int>>& ans) {
        // Base cases
        if (target < 0) return; // No valid combination
        if (target == 0) {      // Found a valid combination
            ans.push_back(combin);
            return;
        }

        for (int i = idx; i < candidates.size(); i++) {
            // Include the current candidate
            combin.push_back(candidates[i]);
            // Recursive call with the same index (allow multiple uses of the same element)
            getAllCombin(candidates, i, target - candidates[i], combin, ans);
            // Backtrack
            combin.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combin;
        getAllCombin(candidates, 0, target, combin, ans);
        return ans;
    }
};
