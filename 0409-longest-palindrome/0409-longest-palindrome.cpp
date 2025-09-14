class Solution {
public:
    int longestPalindrome(string s) {
        
        unordered_map<char, int> mpp;

        int count = 0;

        for(char c : s){

            mpp[c]++;
        }

        bool hasOdd = false;

        for(auto &i : mpp){

            if(i.second % 2 == 0){

                count += i.second;
            } else {

                count += i.second - 1;
                hasOdd = true;
            }
        }

        if(hasOdd) count++;

        return count;
    }
};