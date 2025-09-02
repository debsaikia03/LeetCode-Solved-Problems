class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<char, int> seen;
        int l = 0, len = 0;

        for(int r = 0; r < s.size(); r++){

           if(seen.count(s[r]) && seen[s[r]] >= l){

               l = seen[s[r]] + 1;
           }

            seen[s[r]] = r;
            len = max(len, r - l + 1);
        }

        return len;
    }
};