class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_set<char> seen;
        int l = 0, len = 0;

        for(int r = 0; r < s.length(); r++){

            while(seen.count(s[r])){

                seen.erase(s[l]);
                l++;
            }

            seen.insert(s[r]);
            len = max(len, r - l + 1);
        }

        return len;       
    }
};