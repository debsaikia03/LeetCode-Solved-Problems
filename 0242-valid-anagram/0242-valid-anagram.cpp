class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size() != t.size()) return false;

        unordered_map<char, int> mpp;

        for(int i = 0; i < s.size(); i++){

            mpp[s[i]]++;
        }

        for(int i = 0; i < t.size(); i++){

            if(mpp.find(t[i]) == mpp.end() || mpp[t[i]] == 0) return false;

            mpp[t[i]]--;
        }
        
        return true;
    }
};