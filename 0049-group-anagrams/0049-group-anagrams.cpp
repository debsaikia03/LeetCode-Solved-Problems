class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<vector<string>> res;

        unordered_map<string, vector<string>> mpp;

        for(string str : strs){

            string temp = str;

            sort(temp.begin(), temp.end());

            mpp[temp].push_back(str);
        }

        for(auto& p : mpp){

            res.push_back(p.second);
        }

        return res; 
        
    }
};