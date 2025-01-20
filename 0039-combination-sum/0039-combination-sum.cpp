class Solution {
public:

    set<vector<int>> s;

    void getAllCombin(vector<int>& candidates, int idx, int target, vector<int>& combin,  vector<vector<int>>& ans){

        //base cases
        if(idx == candidates.size() || target < 0){

            return;
        }

        if(target == 0){
            
            if(s.find(combin) == s.end()){

                ans.push_back(combin);
                s.insert(combin);
            }
            
            return;
        }

        combin.push_back(candidates[idx]);

        //include single time
        getAllCombin(candidates, idx+1, target - candidates[idx], combin, ans);

        //include multiple times
        getAllCombin(candidates, idx, target - candidates[idx], combin, ans);

        //exclude 
        combin.pop_back(); //backtracking since number excluded
        getAllCombin(candidates, idx+1, target, combin, ans);


    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans;

        vector<int> combin;

        getAllCombin(candidates, 0, target, combin, ans);

        return ans;

    }
};